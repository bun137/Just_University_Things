import pandas as pd
import matplotlib.pyplot as plt

# Read the dataset
anime_data = pd.read_csv('/path/to/anime_dataset.csv')

# Group the data by category
grouped_data = anime_data.groupby('category')

# Create a boxplot for each category
for category, data in grouped_data:
    # Extract the ratings for the category
    ratings = data['rating']
    
    # Create the boxplot
    plt.boxplot(ratings)
    
    # Set the title and labels
    plt.title(f'Boxplot of Ratings for {category}')
    plt.xlabel('Category')
    plt.ylabel('Rating')
    
    # Display the boxplot
    plt.show()
