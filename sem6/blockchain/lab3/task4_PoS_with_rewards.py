import random

def proof_of_stake_with_rewards(participants, iterations):
    rewards = {participant: 0 for participant in participants}
    for i in range(iterations):
        validator = random.choices(
            list(participants.keys()), weights=participants.values(), k=1
        )[0]
        rewards[validator] += 10
        print(f"Round {i+1}: Block validated by {validator}. Current Rewards: {rewards}")
    
    print("\nFinal Rewards:", rewards)

participants = {"Alice": 50, "Bob": 30, "Charlie": 20}
proof_of_stake_with_rewards(participants, iterations=10)

