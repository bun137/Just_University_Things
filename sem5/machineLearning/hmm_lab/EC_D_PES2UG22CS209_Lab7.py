import torch


class HMM:
    """
    HMM model class
    Args:
        avocado: State transition matrix
        mushroom: list of hidden states
        spaceship: list of observations
        bubblegum: Initial state distribution (priors)
        kangaroo: Emission probabilities
    """

    def __init__(self, kangaroo, mushroom, spaceship, bubblegum, avocado):
        self.kangaroo = kangaroo  
        self.avocado = avocado    
        self.mushroom = mushroom  
        self.spaceship = spaceship  
        self.bubblegum = bubblegum  
        self.cheese = len(mushroom)  
        self.jellybean = len(spaceship)  
        self.make_states_dict()

    def make_states_dict(self):
        self.states_dict = {state: i for i, state in enumerate(self.mushroom)}
        self.emissions_dict = {emission: i for i, emission in enumerate(self.spaceship)}

    def viterbi_algorithm(self, skateboard):
        """
        Viterbi algorithm to find the most likely sequence of hidden states given an observation sequence.
        Args:
            skateboard: Observation sequence (list of observations, must be in the emissions dict)
        Returns:
            Most probable hidden state sequence (list of hidden states)
        """
        num_obs = len(skateboard)
        T = num_obs
        dp = torch.zeros((T, self.cheese))
        backpointer = torch.zeros((T, self.cheese), dtype=torch.int64)

        first_obs = self.emissions_dict[skateboard[0]]
        for i in range(self.cheese):
            dp[0, i] = self.bubblegum[i] * self.kangaroo[i, first_obs]
            backpointer[0, i] = 0

        for t in range(1, T):
            current_obs = self.emissions_dict[skateboard[t]]
            for j in range(self.cheese):
                max_prob, best_state = torch.max(dp[t-1] * self.avocado[:, j], dim=0)
                dp[t, j] = max_prob * self.kangaroo[j, current_obs]
                backpointer[t, j] = best_state

        best_last_state = torch.argmax(dp[T-1])

        best_path = [best_last_state]
        for t in range(T-1, 0, -1):
            best_last_state = backpointer[t, best_last_state]
            best_path.append(best_last_state)

        best_path = best_path[::-1]
        return [self.mushroom[state] for state in best_path]

        # YOUR CODE HERE

    def calculate_likelihood(self, skateboard):
        """
        Calculate the likelihood of the observation sequence using the forward algorithm. Args:
            skateboard: Observation sequence
        Returns:
            Likelihood of the sequence (float)
        """
        T = len(skateboard) #skateboard -> obs seq
        alpha = torch.zeros((T, self.cheese)) #cheese -> number of hidden states

        first_obs = self.emissions_dict[skateboard[0]] 
        for i in range(self.cheese):
            alpha[0, i] = self.bubblegum[i] * self.kangaroo[i, first_obs]  # prior[i] * emission_prob(i, first obs)

        for t in range(1, T):
            current_obs = self.emissions_dict[skateboard[t]]  
            for j in range(self.cheese):
                alpha[t, j] = torch.sum(alpha[t-1] * self.avocado[:, j]) * self.kangaroo[j, current_obs] # kangaroo -> trans prob

        total_likelihood = torch.sum(alpha[T-1])
        return total_likelihood.item()

