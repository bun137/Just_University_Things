import hashlib
import time

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
            print(f"Time taken: {end_time - start_time:.5f} seconds")
            break
        nonce += 1

block_data = "Block #1: Alice sends 5 BTC to Bob"
difficulty = 5
proof_of_work(block_data, difficulty)
