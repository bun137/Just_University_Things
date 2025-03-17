import hashlib
import time
import random

def proof_of_work(block_data, difficulty):
    prefix = "0" * difficulty
    nonce = 0
    start_time = time.time()
    
    while True:
        text = block_data + str(nonce)
        hash_result = hashlib.sha256(text.encode()).hexdigest()
        if hash_result.startswith(prefix):
            end_time = time.time()
            print(f"Block mined! Nonce: {nonce}")
            print(f"Hash: {hash_result}")
            print(f"Time taken: {end_time - start_time:.2f} seconds")
            break
        nonce += 1

def proof_of_stake(participants):
    total_stake = sum(participants.values())
    print("Participants and Stakes:", participants)
    print(f"Total Stake: {total_stake}")
    
    validator = random.choices(
        list(participants.keys()),
        weights=participants.values(),
        k=1
    )[0]
    
    print(f"Selected Validator: {validator}")

def compare_consensus():
    print("\n--- Proof of Work Simulation ---")
    proof_of_work("Sample Block Data", difficulty=4)

    print("\n--- Proof of Stake Simulation ---")
    proof_of_stake({"Alice": 50, "Bob": 30, "Charlie": 20})

# Run the comparison
compare_consensus()

