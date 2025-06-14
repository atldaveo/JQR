# Issue 81: Describe the following concepts related to regular expressions

## Basic Regular Expressions (BRE)
Regular expressions (REGEX) are sequences of characters that define search patterns - specifically for searching, replacing, extracting, and validating text strings. UNIX operating systems typically use the POSIX-standard basic REGEXs (BRE). Characteristics include:
- Limited Metacharacters (Special Characters)
- Backslashes for Metacharacters (Otherwise assumed as literals without a backslash)
- Alternation is not directly supported
- Support for basic character classes (single character, negation, and character class)

Supported metacharacters include: 
"."   (match any single character except newline) 
"*"   (match 0 or more of preceding character)
"[]"  (matches any one character within brackets)
"^"   (matches the start of a line)
"$"   (Matches the end of a line)
"\"   (escapes the following character - treats metacharacters literally) 

## Extended Regular Expressions (ERE)
EREs add more capabilities to BRE such as more metacharacter options, grouping using parentheses, alternations for choices, and greater expressive power for more complex pattern-matching.

ERE supports all BRE metacharacters as well as the additional ones below:
"+"     (matches one or more of the preceding element)
"?"     (matches zero or one of the preceding element)
"`"     (matches literal text between backticks)
"()"    (groups multiple tokens together and captures the matched text)
"{}"    (Specifies number of occurrences of the preceding element)
"\"     (Metacharacters are NOT treated as special characters)


## Perl-Compatible Regular Expressions (PCRE)
More feature-rich than REGEX. Key characteristics include lookarounds, possessive quantifiers, backreferencing, and atomic groups.

Additional metacharacters include:
"(?=...)"   (Positive lookahead. Matches characters ahead of ... )
"(?!...)"   (Negative lookahead. Matches characters not ahead of ...)
"(?<=...)"  (Positive lookbehind. Matches characters behind ... )
"(?<!...)"  (Negative lookbehind. Matches characters not behind ...)
"(?>...)"   (Atomic Group. Prevents backtracking into ...)
"(?<name>...)"  (Named groups. Names a capturing group)
"\k<name>"      (Named backreference. Refers to a previously named backreference)
"*+", "++", "?+"    (Possessive quantifiers. Prevents backtracking)

## Using REGEX on Command Line
Commands:
- grep (Global Regular Expression Parser. Searches through plain-text files that match REGEX)
- sed (Stream Editor. Text editor that manipulates text in a stream / file using REGEX)
- awk (Programming language and command line utility for pattern scanning and processing)

## Works Cited
Gopalakrishna D. 00_Regex_Concepts.md. [Class Resource]. Basic Level Curriculum 
Repository; 2024. [US Army Cyber School]. 