# your solution goes here

num_accidentals = int(input())
accidental_str = input()

flat_length = accidental_str.count('b')
sharp_length = accidental_str.count('#')
if flat_length == sharp_length:
    print("0")
else:
    output_length = abs(flat_length - sharp_length)
    if flat_length > sharp_length:
        print('b' * output_length)
    else:
        print('#' * output_length)


        


