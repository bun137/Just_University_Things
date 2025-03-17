import random

def proof_of_stake(participants):
	total_stake = sum(participants.values())
	print("Participants and Stakes:", participants)
	print(f"Total Stake: {total_stake}")

	validator = random.choices(
    	list(participants.keys()), weights=participants.values(), k=1
	)[0]

	print(f"Selected Validator: {validator}")

participants = {"Alice": 50, "Bob": 30, "Charlie": 20}
proof_of_stake(participants)

