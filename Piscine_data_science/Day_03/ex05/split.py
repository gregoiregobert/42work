import sys
import os
import pandas as pd
from sklearn.model_selection import train_test_split


def determine_target(df):
    X = df.drop(columns=['knight'])
    y = df['knight']
    return (X, y)

def split_to_csv(X ,y):
    # Étape 1 : Diviser en ensemble d'entraînement (60%) et ensemble test+validation (40%)
    X_train, X_temp, y_train, y_temp = train_test_split(X, y, test_size=0.4, random_state=42)

    # Étape 2 : Diviser l'ensemble temporaire (X_temp, y_temp) en validation (20%) et test (20%)
    X_val, X_test, y_val, y_test = train_test_split(X_temp, y_temp, test_size=0.5, random_state=42)

    train_df = pd.concat([X_train, y_train], axis=1)
    train_df.to_csv('Training_knight.csv', index=False)

    val_df = pd.concat([X_val, y_val], axis=1)
    val_df.to_csv('Validation_knight.csv', index=False)

def main():
    df = pd.read_csv(f"{os.getcwd()}/Train_knight.csv")
    X, y = determine_target(df) 
    split_to_csv(X,y)

if __name__ == "__main__":
    main()
