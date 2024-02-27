### Note

This is a hash algorithm that produces a readable hash text instead of number. 

### How it works:

it has a list of adjectives and a list of names: 

    INDEX   |    ADJE_OPTIONS     |   NAME_OPTIONS         
    ----------------------------------------------    
      0     |    enthusiastic     |       billy       
      1     |    humble           |       jacky       
      2     |    brave            |       larry       
      3     |    heuristic        |       sally       
      4     |    clever           |       vicky       
      5     |    compassionate    |       jerry       
      6     |    artistic         |       danny       
      7     |    unconventional   |       harry       
      8     |    lucky            |       renny       
      9     |    abstract         |       kelly       
      10    |    wise             |       annie       
      11    |    sharp            |       patty       
      12    |    intrepid         |       rummi       
      13    |    nurtring         |       terry       
      14    |    experimental     |       toby        
      15    |    unlucky          |       hommer      


There are two vectors of 16 items, that can generate 16 * 16 = 256 combiations.
The same number of combinations in an 8 bit hash 2^8 = 256.

This way one can encode a hash function to retrive a readable number.


So a simple 8 bit hash is produced and then is mapped to the vectors index.
Plese note the hash used here is not viable for secure criptographic schemas, it is just for illustration, but one can use the same technique to expand on it.