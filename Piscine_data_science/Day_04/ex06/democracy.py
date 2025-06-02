import sys
import pandas as pd
from sklearn.ensemble import VotingClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import f1_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import GridSearchCV

# Loading datas
def load_data():
    train_df = pd.read_csv('../ex04/Train_knight.csv')
    test_df = pd.read_csv('../ex04/Test_knight.csv')

    scaler = StandardScaler()
    test_df_scaled = scaler.fit_transform(test_df)

    return train_df, test_df_scaled

def train_model(train_df):
   
    train_df['knight'] = train_df['knight'].map({'Sith': 0, 'Jedi': 1})
    X = train_df.drop(columns= 'knight')    # Features
    y = train_df['knight']                  # Target

    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)

    # Splitting data (20% for validation)
    X_train, X_val, y_train, y_val = train_test_split(X_scaled, y, test_size=0.2, random_state=42)

    # Generating and training model
    knn_clf = KNeighborsClassifier(n_neighbors=7)
    tree_clf = RandomForestClassifier(n_estimators=15)
    logr_clf = LogisticRegression()

    voting_clf = VotingClassifier(estimators=[
        ('lr', logr_clf), 
        ('rt', tree_clf), 
        ('knn', knn_clf)
    ], voting='hard')

    voting_clf.fit(X_train, y_train)

    # Validate model
    y_val_pred = voting_clf.predict(X_val)
    f1 = f1_score(y_val, y_val_pred)
    print(f"Validation_set F1 Score: {f1 * 100:.2f}%")
    
    return voting_clf

def predict_and_save(model, test_df):
    predictions = model.predict(test_df)
    predictions = ['Jedi' if pred == 1 else 'Sith' for pred in predictions]                      # ICI
    
    with open("Tree.txt", 'w') as f:
        for pred in predictions:
            f.write(f"{pred}\n")

def main():
    # Load the data
    train_df, test_df = load_data()

    # Train the model
    model = train_model(train_df)

    # Make predictions and save to Tree.txt
    predict_and_save(model, test_df)


if __name__ == "__main__":
    main()
