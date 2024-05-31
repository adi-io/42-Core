import pandas as pd

df = pd.read_csv('data.csv', header=None, names=['date', 'exchange_rate'])
df = df[df['date'] != 'date']  # Filter out any rows where 'date' appears

df['date'] = pd.to_datetime(df['date'], errors='coerce')
df.set_index('date', inplace=True)

complete_date_range = pd.date_range(start=df.index.min(), end=df.index.max(), freq='D')
df = df.reindex(complete_date_range)
df['exchange_rate'] = df['exchange_rate'].fillna(method='ffill')

df.reset_index(inplace=True)
df.columns = ['date', 'exchange_rate']
df.to_csv('cleaned_data.csv', index=False)

