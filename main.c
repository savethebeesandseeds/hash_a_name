/**
 * Program Name: Hash a Name
 * Description:
 * This program is designed to generate unique identifiers by hashing input strings
 * and then mapping those hash values to specific names and adjectives. The main functionality
 * is implemented across two primary functions:
 * 
 * 1. `simple_hash_8`: A simple hashing function that takes a string and computes an 8-bit hash value.
 * 2. `hash_a_name`: Takes an input string, hashes it using `simple_hash_8`, and then uses the hash
 *    to generate a unique identifier by selecting from predefined arrays of names and adjectives.
 * 
 * Compile with: gcc -o hash_a_name main.c -std=c99
 * 
 * Usage:
 * After compilation, you can run the program by executing `./hash_a_name` in the terminal. 
 *
 * Author: Waajacu
 * Date: 27/02/20224
 */
#include <stdio.h>

#define NAME_OPTIONS "billy", "jacky", "larry", "sally", "vicky", "jerry", "danny", "harry", "renny", "kelly", "annie", "patty", "rummi", "terry", "toby", "hommer"
#define ADJE_OPTIONS "enthusiastic", "humble", "brave", "heuristic", "clever", "compassionate", "artistic", "unconventional", "lucky", "abstract", "wise", "sharp", "intrepid", "nurtring", "experimental", "unlucky"
/**
 * Computes a simple hash value for a given string.
 * 
 * This function implements a basic hashing algorithm by iterating over each character of the input string,
 * applying a specific formula to accumulate a hash value. For each character in the string, the hash value 
 * is updated by left-shifting the current hash value by 5 positions, adding the original hash value to this 
 * result, and then adding the ASCII value of the current character. The modulo 256 operation ensures that the 
 * final hash value fits within an unsigned char (0-255 range). This simple approach provides a rudimentary 
 * way to generate a hash value that can be used for basic data mapping or distribution purposes.
 *
 * @param str Pointer to the null-terminated string to be hashed.
 * @return An unsigned char representing the computed hash value of the input string.
 */

unsigned int simple_hash_8(const char* str) {
    unsigned int hash_value = 5381; /* Initial basis for the hash */
    while (*str) {
        hash_value = (((hash_value << 5) + hash_value) + *str) % 256;
        str++; /* Move to the next character */
    }
    return hash_value;
}

/**
 * Generates a unique identifier based on a hash of the input string.
 *
 * This function takes an input string and applies a simple hashing algorithm to generate a unique numerical value.
 * It then uses this hash value to select elements from predefined arrays of name and adjective options to construct
 * a unique identifier. The identifier is composed by concatenating a selected name and adjective, separated by an
 * underscore. The selection process divides the hash value into two parts: the upper four bits are used to index into
 * the name options array, and the lower four bits are used to index into the adjective options array.
 *
 * Preconditions:
 * - `in` must be a null-terminated string.
 * - `out` must be a buffer large enough to hold the resulting identifier, including the null terminator.
 * - `NAME_OPTIONS` and `ADJE_OPTIONS` must be defined and contain at least 16 null-terminated strings each, as the
 *   indexing is based on a 4-bit value (ranging from 0 to 15).
 *
 * @param in Pointer to the input null-terminated string to hash.
 * @param out Pointer to the output buffer where the resulting identifier is stored.
 */

void hash_a_name(const char* in, char *out) {
    const char* name_options[] = { NAME_OPTIONS };
    const char* adje_options[] = { ADJE_OPTIONS };
    
    unsigned char hash_num = simple_hash_8(in);

    size_t name_index = hash_num >> 4;  /* first four bites */
    size_t adje_index = hash_num & 0xF; /* second four bites */

    sprintf(out, "%s_%s", adje_options[adje_index], name_options[name_index]);
}

int main() {
    char hash_n[512];
    const char* source = "Hello, world!";
    
    hash_a_name(source, hash_n);

    /* it would print: [Hello, world!] --fx--> [experimental_annie] */
    fprintf(stdout, "[%s] --fx--> [%s]\n", source, hash_n);
    return 0;
}
