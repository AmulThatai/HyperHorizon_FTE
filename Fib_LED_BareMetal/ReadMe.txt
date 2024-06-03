Project can be simulated on https://wokwi.com/projects/399632813402870785

Code is a fibonacci counter, that loops back.

Bonus

For 32 bit numbers, we can divide the fibonacci number (f) into 4 parts(from least to most significant):
Part 1: f%2^8
Part 2: f&2^16, then right shift this number by 8 bits
Part 3: f&2^24, then right shift this number by 16 bits
Part 4: right shift fibonacci number by 24 bits

Part 1 can be assigned to least significant port. Port 2 to the next and so on up to port 4.