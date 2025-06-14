# Issue 80: Describe libraries commonly used to aid in serialization

## C
### JSON-C ("json.h")
JSON (or Javascript Object Notation) is a human-readable text serialization method that uses a reference counting object model to serialize data into JSON-formatted strings and vice-versa. Text is parsed into json objects in a json object tree (Hawicz 2024). 

### MessagePack ("cmp.h")
Smaller and faster than JSON. This binary serialization library enables the encoding of small integers using only one byte and short strings using only one byte more than the size of the string (Furuhashi 2021).  

### CBOR ("cb0r.h", "qcbor_encode.h", "qcbor_decode.h")
Concise Binary Object Representation (CBOR) is based on JSON objects without the need for many JSON-specific overhead such as binary. This serialization library is thus optimal for small data encoding/decoding such as in micro-controller / IoT or embedded systems development. However, CBOR has been adapted to many different needs and languages with an RFC-8949 standard stability (Bormann 2020).

### YAML ("cyam1/cyam1.h")
Human-readable serialization language. YAML is a strict superset of JSON typically used for writing configuration files. However, base-YAML strictly adheres to indentation rules similar to Python (Lemonaki 2022). 

### XML ("cxml/cxml.h")
Extensible Markup Language. Like YAML and JSON, XML is also a popular method of writing configuration files. Widely used for complex configurations and fine control over schema validation due to its flexible structure/syntax (Lemonaki 2022). 

## Python
### Pickle (pickle)
Built-in Python module. Pickling is a binary serialization method - an upgrade from a more primitive "marshal" module. Allows for quick and simple serial/deserialization of vast numbers of Python objects into a byte-stream (whereas JSON can only execute on some Python objects) and is not human-readable. Python object compatibility can be enhanced with the `dill` extension. However, this serialization method lacks security features; unpickling unvetted, malicious code may lead to the execution of arbitrary code (Pickle 2025).    

### Protobuf (google3, google.protobuf)
Protocol buffers is a language-neutral, platform-neutral serialization solution developed by Google. Benefits and use-cases for this library are interoperability, compactness, speed, and simplicity (Protocol Buffers 2008).

### JSON (json), MessagePack (msgpack), YAML (pyyaml), XML (xml), and CBOR (cbor) also have API for Python 

## Works Cited
Bormann C. CBOR. [Internet]. University of Bremen; 2020. [Accessed 2025 Jan 25]. Available from: https://cbor.io/

Furuhashi S. MessagePack. [Internet]. MessagePack; 2021. [Accessed 2025 Jan 25]. Available from: https://msgpack.org/

Hawicz E. JSON-C - A JSON implementation in C. [Internet]. JSON; 2024 Sep 15. [Accessed 2025 Jan 25]. Available from: https://github.com/json-c/json-c/wiki

Lemonaki D. What is YAML? The YML File Format. [Internet] Free Code Camp; 2022 Nov 11. [Accessed 2025 Jan 25]. Available from: https://www.freecodecamp.org/news/what-is-yaml-the-yml-file-format/

Pickle - Python object serialization. [Intenet]. Python Software Foundation; 2025. [Accessed 2025 Jan 25]. Available from: https://docs.python.org/3/library/pickle.html 

Protocol Buffers. [Internet]. Google; 2008. [Accessed 2025 Jan 25]. Available from:  https://protobuf.dev/
