import pandas as pd

data = pd.read_excel('../../../Downloads/titanic.xls')
data = data.drop(['sibsp', 'parch', 'ticket', 'fare', 'cabin', 'embarked', 'boat', 'body', 'home.dest', 'name'], axis=1)
data = data.dropna()