import random

def proof_of_stake(validators):
    total_stake = sum(validators.values())
    selected_validator = random.choices(
        list(validators.keys()), weights=validators.values(), k=1
    )[0]
    return selected_validator

def distribute_rewards(validators, delegators, validator, reward):
    total_stake = sum(validators.values())
    validator_stake = validators[validator]
    
    for delegator in delegators[validator]:
        stake_ratio = delegators[validator][delegator] / validator_stake
        delegators[validator][delegator] += stake_ratio * reward
    
    print(f"Rewards Distributed: {reward} to validator {validator} and delegators")
    return delegators

def slashing(validators, delegators, validator, slash_percent):
    if random.random() < 0.2:  
        slash_amount = validators[validator] * slash_percent
        validators[validator] -= slash_amount
        print(f"Validator {validator} caught cheating! Slashed {slash_amount}")
        
        for delegator in delegators[validator]:
            delegators[validator][delegator] *= (1 - slash_percent)
    return validators, delegators

def staking_simulation(validators, delegators, rounds=5, reward_per_block=10, slash_percent=0.5):
    for round_num in range(1, rounds + 1):
        print(f"\n--- Round {round_num} ---")
        validator = proof_of_stake(validators)
        delegators = distribute_rewards(validators, delegators, validator, reward_per_block)
        validators, delegators = slashing(validators, delegators, validator, slash_percent)
        print(f"Updated Stakes: {validators}")
        print(f"Updated Delegators: {delegators}")

validators = {"Alice": 50, "Bob": 30, "Charlie": 20}
delegators = {
    "Alice": {"X": 30, "Y": 20},
    "Bob": {"Z": 20, "W": 10},
    "Charlie": {"U": 10, "V": 10}
}

staking_simulation(validators, delegators)
