import csv
import os

# Function to read and process the CSV file
def read_csv_file(file_name):
  with open(file_name, newline='') as csvfile:
    # Create a CSV reader object
    csv_reader = csv.reader(csvfile)

    # Read the header row
    header = next(csv_reader)

    # Initialize an empty list to store the data
    data = []

    # Loop through the remaining rows and store the data in a list
    for row in csv_reader:
      data.append(row[0])

  return header, data

# File name of the CSV file to read
csv_file = 'sudoku.csv'

# Call the function to read the CSV file
header, data = read_csv_file(csv_file)

# Function to create and write integers to a file
def write_integers_to_file(file_name, integers):
  with open(file_name, 'w') as file:
    for number in integers:
      file.write(str(number))
    file.write('\n')

# Create files and write integers to each file
for i, number in enumerate(data[:10], start=1):
  file_name = f"puzzle_{i}.txt"
  write_integers_to_file(file_name, [number])
