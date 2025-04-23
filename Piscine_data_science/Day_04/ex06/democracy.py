import sys
import pandas as pd
from sklearn.ensemble import VotingClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
from sklearn.metrics import f1_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Loading datas
def load_data(Train_knight, Test_knight):
    train_df = pd.read_csv(Train_knight)
    test_df = pd.read_csv(Test_knight)

    scaler = StandardScaler()
    test_df_scaled = scaler.fit_transform(test_df)

    return train_df, test_df_scaled

def train_model(train_df):
   
    train_df['knight'] = train_df['knight'].map({'Sith': 0, 'Jedi': 1})
    X = train_df.drop(columns= 'knight')  # Features
    y = train_df['knight']   # Target

    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)

    # Splitting data (20% for validation)
    X_train, X_val, y_train, y_val = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

    # Generating and training model
    log_clf = LogisticRegression()
    tree_clf = DecisionTreeClassifier()
    svm_clf = SVC(probability=True)

    voting_clf = VotingClassifier(estimators=[
        ('lr', log_clf), 
        ('dt', tree_clf), 
        ('svc', svm_clf)
    ], voting='hard')

    voting_clf.fit(X_train, y_train)

    # Validate model
    y_val_pred = voting_clf.predict(X_val)
    f1 = f1_score(y_val, y_val_pred)
    print(f"Validation_set F1 Score: {f1 * 100:.2f}%")
    
    return voting_clf

def predict_and_save(model, test_df):
    predictions = model.predict(test_df)
    
    with open("Tree.txt", 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")

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


if __name__ == "__main__":
    main()
