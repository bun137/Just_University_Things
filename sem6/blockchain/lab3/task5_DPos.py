import random

participants = {
    "Alice": 50,
    "Bob": 30,
    "Charlie": 20,
    "Dave": 40,
    "Eve": 60
}

def vote_for_delegates(participants, num_votes=2):
    votes = {p: [] for p in participants.keys()}
    for voter in participants.keys():
        votes[voter] = random.sample(list(participants.keys()), num_votes)
    return votes

def select_delegates(votes, num_delegates=3):
    vote_count = {p: 0 for p in participants.keys()}
    for voter, delegate_list in votes.items():
        for delegate in delegate_list:
            vote_count[delegate] += participants[voter]  # Weight votes by stake
    
    sorted_delegates = sorted(vote_count.items(), key=lambda x: x[1], reverse=True)
    return [d[0] for d in sorted_delegates[:num_delegates]]

def validate_block(delegates):
    validator = random.choice(delegates)
    print(f"Block validated by: {validator}")

votes = vote_for_delegates(participants)
print("Votes:")
for voter, delegates in votes.items():
    print(f"{voter} voted for: {', '.join(delegates)}")

delegates = select_delegates(votes)
print("Selected Delegates:", delegates)

validate_block(delegates)
