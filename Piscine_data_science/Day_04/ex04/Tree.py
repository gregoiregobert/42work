import sys
import pandas as pd
from sklearn.tree import plot_tree
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import f1_score
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Loading datas
def load_data(Train_knight, Test_knight):
    train_df = pd.read_csv(Train_knight)
    test_df = pd.read_csv(Test_knight)
    return train_df, test_df

# Train model
def train_model(train_df, f1_array):
    X = train_df.drop(columns= 'knight')  # Features
    y = train_df['knight']   # Target

    # Splitting data (20% for validation)
    X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)

    # Generating and training model
    model = RandomForestClassifier(n_estimators=15)
    model.fit(X_train, y_train)

    # Validate model
    y_val_pred = model.predict(X_val)
    f1 = f1_score(y_val, y_val_pred, pos_label='Jedi')
    f1_array.append(f1)
    print(f"Validation_set F1 Score: {f1 * 100:.2f}%")
    
    return model

def predict_and_save(model, test_df):
    predictions = model.predict(test_df)
    
    with open("Tree.txt", 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")

def visualize_tree(model, feature_names):
    estimator = model.estimators_[0]  # Choisir un arbre de la forêt

    plt.figure(figsize=(20, 10))
    plot_tree(estimator, 
              feature_names=feature_names,
              class_names=['Jedi', 'Sith'],
              filled=True)
    plt.title(f"Premier arbre du Random Forest")
    plt.show()

def print_f1_scores(f1_array):

    plt.figure(figsize=(8, 5))
    plt.plot(range(len(f1_array)), f1_array, marker='o', linestyle='-', color='seagreen')
    plt.ylabel("F1-score")
    plt.ylim(0, 1)
    plt.axhline(y=0.90, color='red', label='90%')
    plt.grid(True)
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
    f1_array = []
    for _ in range(100):
        model = train_model(train_df, f1_array)

    print_f1_scores(f1_array)

    # Make predictions and save to Tree.txt
    predict_and_save(model, test_df)

    visualize_tree(model, feature_names=train_df.columns[:-1])

if __name__ == "__main__":
    main()
