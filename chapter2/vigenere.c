#include <stdio.h>
#include <cs50.h>

int string_length (char *string)
{
    int length;
    for (length = 0; string[length] != '\0'; length++);
    return length;
}

bool is_lower (char character)
{
    return (character >= 'a' && character <= 'z');
}

bool is_alpha (char character)
{
    return (character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z');
}

void encrypt (char character, int key)
{
    // The 97 and 65 are for going to and from the alphabetical enumeration
    // printf("%i", key);
    int text_reference = (is_lower(character) ? 'a' : 'A');
    printf("%c", (((character + (key  - (is_lower(key) ? 'a' : 'A'))) - text_reference) % 26) +
        text_reference);
}

int main (int argc, char **argv)
{
    // There must be two arguments
    if (argc != 2)
    {
        printf("No key provided");
        return 1;
    }

    // Get the key, turn it into an int
    char *key = argv[1];
    for (int i = 0, l = string_length(key); i < l; i++)
    {
        if (!is_alpha(key[i]))
        {
            return 1;
        }
    }

    // Get plaintext
    char *plaintext = get_string("plaintext: ");


    printf("ciphertext: ");
    for (int i = 0, key_index = 0, l = string_length(plaintext); i < l; i++)
    {
        // Check if the char is in the alphabet
        if (is_alpha(plaintext[i]))
        {
            encrypt(plaintext[i], key[key_index % string_length(key)]);
            key_index++;
        }
        // If character is not alphabetic just print the character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
