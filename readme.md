## C Hashmap

A dynamic key-value store is a necessary data structure for many algorithms.
This hashmap is an implemenation of an associative array in C.

The hash is very simple, using the modulus of the sum of ASCII characters of the key to derive index.

The initial size of the hashmap can be configured, as can the maximum number of links permitted before the map is rehashed.
The interplay of these two numbers determines the speed of reads vs writes as well as rehashing.
Choosing too small an initial hashmap will lead to greater link depths. Too large a map will cause wasted memory.
The choice of max link depth will determine how soon rehashing occurs too. A small number will suffer the overhead of rehashing earlier,
whereas a larger number increases the read latency, as the linked list will require more iteration to reach the values stored at their ends.

At time of rehashing, the length of the map is doubled.

### Example
The test file shows an example of use, as well as a nanosecond benchmark score.
Performance changes can be observed by altering the initial length and maximum depth.

### TODO

- [] refactor

