import hashlib

def hash_data(data: str) -> str:
    """Return the SHA-256 hash of the input string."""
    return hashlib.sha256(data.encode()).hexdigest()

def build_merkle_tree(transactions):
    """
    Build all levels of the Merkle Tree (from leaves up to the root),
    and return a list of levels.
    
    levels[0] = list of leaf hashes
    levels[1] = list of parent hashes
    ...
    levels[-1] = [merkle_root]
    """
    if not transactions:
        return []

    # 1) Compute leaf hashes
    current_level = [hash_data(tx) for tx in transactions]
    levels = [current_level]  # levels[0] is the leaf level

    # 2) Build upwards until there's only one hash (the root)
    while len(current_level) > 1:
        next_level = []
        for i in range(0, len(current_level), 2):
            left = current_level[i]
            right = current_level[i + 1] if i + 1 < len(current_level) else left
            next_level.append(hash_data(left + right))
        levels.append(next_level)
        current_level = next_level

    return levels

def build_merkle_proofs(transactions):
    """
    Build the Merkle Tree for the given transactions, then construct and return
    the proofs for each transaction, along with the Merkle root.

    Returns: (merkle_root, proof_dict)

    proof_dict[tx] will be a list of (direction, sibling_hash), where:
      - direction == 'L' means sibling is to the LEFT (you do sibling + current)
      - direction == 'R' means sibling is to the RIGHT (you do current + sibling)
    """
    # 1) Build all levels of the Merkle Tree
    levels = build_merkle_tree(transactions)
    if not levels:
        return "", {}

    merkle_root = levels[-1][0]  # single element in last level is the root
    proof_dict = {}

    # 2) Build proofs by tracing each leaf up the tree
    leaves = levels[0]  # The very first level holds the leaf hashes
    for tx_index, tx in enumerate(transactions):
        # We'll reconstruct the path from leaf up to the root
        proof = []
        current_hash_index = tx_index  # position in the leaf level

        # Walk through each level, up to but NOT including the root level
        for level_idx in range(len(levels) - 1):
            level = levels[level_idx]
            # Identify sibling index
            is_right_node = (current_hash_index % 2 == 1)
            if is_right_node:
                # If current node is right, sibling is to the left
                sibling_index = current_hash_index - 1
                direction = 'L'  # sibling goes on the LEFT side during verify
            else:
                # If current node is left (or alone at the end), sibling is to the right
                sibling_index = current_hash_index + 1
                direction = 'R'  # sibling goes on the RIGHT side during verify

            # If sibling index is out of range (odd number of nodes), we "duplicate" the current node
            if sibling_index >= len(level):
                sibling_index = current_hash_index

            sibling_hash = level[sibling_index]
            proof.append((direction, sibling_hash))

            # Move to parent index for the next level
            current_hash_index //= 2

        proof_dict[tx] = proof

    return merkle_root, proof_dict

def verify_transaction(transaction, proof, merkle_root):
    """
    Verify that a given transaction is in the Merkle Tree by using its proof.
    Each proof element is (direction, sibling_hash).

    - If direction == 'L', the sibling is left: combined_hash = sibling + current
    - If direction == 'R', the sibling is right: combined_hash = current + sibling
    """
    current_hash = hash_data(transaction)
    for direction, sibling_hash in proof:
        if direction == 'L':
            combined = sibling_hash + current_hash
        else:  # direction == 'R'
            combined = current_hash + sibling_hash
        current_hash = hash_data(combined)

    return current_hash == merkle_root

# -----------------------
# Example usage:
if __name__ == "__main__":
    # 1) Some test transactions
    txs = ["tx1", "tx2", "tx3", "tx4"]

    # 2) Build the Merkle root and proofs
    root, proofs = build_merkle_proofs(txs)

    # 3) Print results
    print("Merkle Root:", root)
    print("\nProofs:")
    for tx, proof in proofs.items():
        print(f"Transaction: {tx}, Proof: {proof}")

    # 4) Verify one transaction (e.g., "tx2")
    tx_to_check = "tx2"
    print(f"\nVerifying {tx_to_check}...")
    tx_valid = verify_transaction(tx_to_check, proofs[tx_to_check], root)
    print(f"Is {tx_to_check} valid in the Merkle tree?", tx_valid)
