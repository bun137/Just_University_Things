import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
from torchvision.datasets import ImageFolder
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
import torch.nn.functional as F
# Dataset Preparation do not modify, ensure data folder is in the same directory as this file
def prepareData(path):
    transform = transforms.Compose([transforms.Resize(255),
                                transforms.CenterCrop(64),
                                transforms.RandomVerticalFlip(),
                                transforms.RandomHorizontalFlip(),
                                transforms.ToTensor()])
    #In case you want to change path, change it in Test.py do not make a new path variable
    dataset = ImageFolder(path, transform=transform)
    test_size = 0.2
    num_dataset = len(dataset)
    num_test = int(num_dataset * test_size)
    num_train = num_dataset - num_test
    train_set, test_set = torch.utils.data.random_split(dataset, [num_train, num_test])
    train_loader = torch.utils.data.DataLoader(train_set, batch_size=8, shuffle=True, num_workers=2)
    test_loader = torch.utils.data.DataLoader(test_set, batch_size=8, shuffle=True, num_workers=2)
     

    return train_loader, test_loader

# CNN Model Class
class CNN(nn.Module):
    def __init__(self):
        super().__init__()
        # ----------------------------------------------
        # TODO: Define the CNN layers (Conv layers, Pooling layers, Fully connected layers)
        #----------------------------------------------------------------------------------
        
        self.c1 = nn.Conv2d(in_channels=3, out_channels=16, kernel_size=3, stride=1, padding=1)
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2, padding=0)
        self.c2 = nn.Conv2d(in_channels=16, out_channels=32, kernel_size=3, stride=1, padding=1)
        self.c3 = nn.Conv2d(in_channels=32, out_channels=64, kernel_size=3, stride=1, padding=1)
        self.fc1 = nn.Linear(64 * 8 * 8, 128) 
        self.fc2 = nn.Linear(128, 64)
        self.fc3 = nn.Linear(64, 10)
        self.setCriterionAndOptimizer()
        


    def forward(self, x):
        # ----------------------------------------------
        # TODO: Define the forward pass through the network.
        # Pass x through convolution layers, pooling layers, flatten, and fully connected layers.
        # ----------------------------------------------
        x = self.pool(F.relu(self.c1(x)))
        x = self.pool(F.relu(self.c2(x)))
        x = self.pool(F.relu(self.c3(x)))
        x = x.view(-1, 64 * 8 * 8) 
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.fc3(x)
        return x

    def setCriterionAndOptimizer(self):
        self.optimizer = optim.Adam(self.parameters(), lr=0.002)
        self.criterion = nn.CrossEntropyLoss()

# Training Loop
def train(model, train_loader):
    # Implement training loop here
    # Input: train_loader
    # Output: Train accuracy (float)
    # You can set the epochs
    model.train()
    epochs=10
    running_loss=0
    for epoch in range(epochs):
        correct=total=0
        # ----------------------------------------------
        # TODO: Forward pass, calculate loss, backpropagate and step the optimizer
        # ----------------------------------------------
        
        #--------------------------------
        # TODO: Update the running_loss, correct_predictions and total_samples
        #--------------------------------
        
        for inputs, labels in train_loader:
            model.optimizer.zero_grad()
            outputs = model(inputs)
            loss = model.criterion(outputs, labels)
            loss.backward()
            model.optimizer.step()

            running_loss += loss.item()
            _, predicted = torch.max(outputs, 1)
            correct += (predicted == labels).sum().item()
            total += labels.size(0)
        train_accuracy = 100 * correct / total
        print(f'Epoch {epoch+1} - Train Loss: {running_loss:.4f}, Train Accuracy: {train_accuracy:.2f}%')
    print(f'Train Accuracy: {train_accuracy:.2f}%')
    return train_accuracy

# Evaluation Loop
def evaluate(model, test_loader):
    model.eval()
    correct, total = 0, 0

    with torch.no_grad():
        for inputs, labels in test_loader:
            outputs = model(inputs)
            _, predicted = torch.max(outputs, 1)
            correct += (predicted == labels).sum().item()
            total += labels.size(0)

    test_accuracy = 100 * correct / total
    print(f'Test Accuracy: {test_accuracy:.2f}%')
    return test_accuracy
