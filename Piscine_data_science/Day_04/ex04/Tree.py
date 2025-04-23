import sys
import pandas as pd
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import f1_score
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Loading datas
def load_data(Train_knight, Test_knight):
    train_df = pd.read_csv(Train_knight)
    test_df = pd.read_csv(Test_knight)
    return train_df, test_df

# Train model
def train_model(train_df):
    X = train_df.drop(columns= 'knight')  # Features
    y = train_df['knight']   # Target

    # Splitting data (20% for validation)
    X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

    # Generating and training model
    model = DecisionTreeClassifier(random_state=42)
    model.fit(X_train, y_train)

    # Validate model
    y_val_pred = model.predict(X_val)
    f1 = f1_score(y_val, y_val_pred, pos_label='Jedi')
    print(f"Validation_set F1 Score: {f1 * 100:.2f}%")
    
    return model

def predict_and_save(model, test_df):
    predictions = model.predict(test_df)
    
    with open("Tree.txt", 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")

def plot_decision_tree(model, feature_names):
    plt.figure(figsize=(20, 10))
    plot_tree(model, feature_names=feature_names, class_names=['Jedi', 'Sith'], filled=True)
    plt.show()

def main():

    if len(sys.argv) != 3:
        print("Usage: python Tree.py <Train_knight.csv> <Test_knight.csv>")
        sys.exit(1)

    train_file = sys.argv[1]
    test_file = sys.argv[2]

    # Load the data
    train_df, test_df = load_data(train_file, test_file)

    # Train the model
    model = train_model(train_df)

    # Make predictions and save to Tree.txt
    predict_and_save(model, test_df)

    # To visualize the tree
    plot_decision_tree(model, feature_names=train_df.columns[:-1])

if __name__ == "__main__":
    main()
