import torch
import pandas as pd

# df = pd.read_csv('employeeData.csv')
# data = torch.tensor(df.values, dtype=torch.float32)

# input:tensor
# output:int/float
def get_entropy_of_dataset(tensor:torch.Tensor): 
    labels = tensor[:,-1]
    probab = torch.histc(labels, bins=int(labels.max().item() - labels.min().item()) + 1, min=labels.min(), max=labels.max())
    probab = probab / probab.sum()  
    #probab = probab[probab>0]
    entropy = -torch.sum(probab * torch.log2(probab))  
    return entropy.item()

# input:tensor,attribute number 
# output:int/float
def get_avg_info_of_attribute(tensor: torch.Tensor, attribute: int):
    params = tensor[:, attribute]
    labels = tensor[:, -1]
    uniqueVal, counts = torch.unique(params, return_counts=True)
    totalCou = len(params)
    avgInfo = 0
    
    for value, count in zip(uniqueVal, counts):
        curr = tensor[params == value]
        entropy = get_entropy_of_dataset(curr)
        prob = count / totalCou
        avgInfo += prob * entropy
    return avgInfo.item()

# input:tensor,attribute number
# output:int/float
def get_information_gain(tensor:torch.Tensor, attribute:int):
    totalEntro = get_entropy_of_dataset(tensor)
    avgIn = get_avg_info_of_attribute(tensor, attribute)
    # formula for information gain
    infoGain = totalEntro - avgIn
    return infoGain


# input: tensor
# output: ({dict},int)
def get_selected_attribute(tensor:torch.Tensor):
    """
    Return a tuple with the first element as a dictionary which has IG of all columns
    and the second element as an integer representing attribute number of selected attribute
    

    example : ({0: 0.123, 1: 0.768, 2: 1.23} , 2)
    """
    dict = {}
    for i in range(tensor.shape[1]-1):
        dict[i] = get_information_gain(tensor, i)
    pick = max(dict, key=dict.get)
    return dict, pick
   
# def main():
#     print(get_entropy_of_dataset(data))
#     print(get_avg_info_of_attribute(data, 0))
#     print(get_information_gain(data, 0))
#     print(get_selected_attribute(data))
#
# if __name__ == "__main__":
#     main()
