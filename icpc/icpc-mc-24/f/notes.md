# Problem F - Emoticons

### ICPC Mid-Central Regional Contest

[Link to Problem](https://mcpc24.kattis.com/contests/mcpc24/problems/emoticons2)

Emma posted a message containing emoticons that may be converted to emojis by her social media platform. She accidentally replaced all occurrences of one character in her message with another (this could include replacing with the same character). After this replacement, she wants to know the minimum and maximum possible length of her message after emoticons are converted to emojis. Each emoji should be counted as a single character in the final length calculation.

To incorporate this, we need to handle two cases:
- Maximum Length: Assume replacements result in the maximum number of emoticons being broken and not converted to emojis.
- Minimum Length: Assume replacements may form all possible emoticons, leading to more emojis in the final message.

Here is the steps:
- For each unique character in the message, simulate replacing it with each other character (or the same character, meaning no change).
- After each replacement, count the emoticons that can be converted and calculate the resulting message length.
- Track the minimum and maximum lengths across all possible replacements.

Pseudocode:

```python
allPossible = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "

line = input()

minLength = 101
maxLength = -1

for character1 in allPossible:
    for character2 in allPossible:
        transformed = replaceCharacters(line, character1, character2)
        length = convertEmoticonsToEmoji(transformed).length

        minLength = min(minLength, length)
        maxLength = max(maxLength, length)

output(minLength, maxLength)

function replaceCharacters(source, delimiter, replacement):
    result = ""
    for character in source:
        if character == delimiter:
            result += replacement
        else:
            result += character
    return result

function convertEmoticonsToEmoji(string):
    emoticons = [
        (":)", "☺️"), (":-)", "☺️"), (":-(", "☹️"), (";-)", "😉"),
        ("xD", "😆"), ("^_^", "☺️"), ("-_-", "😑"), ("^o^", "😀"),
        ("^^;", "😅"), ("(..)", "😔")
    ]
    
    for (emoticon, emoji) in emoticons:
        position = 0
        while position != -1:
            position = find position of emoticon in string from last position
            if position is found:
                replace emoticon with emoji at position
                move position forward past the emoji
    return string

```