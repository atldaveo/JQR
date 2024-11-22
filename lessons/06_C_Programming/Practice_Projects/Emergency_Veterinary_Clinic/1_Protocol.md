# Emergency Veterinary Management System: Serialization Protocol

Each appointment record shall be written sequentially to the data file in the following format:

```text
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|    Severity   |    Name Len   |  Species Len  |    PADDING    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|            PADDING            |       Description Length      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                                                               |
+                                                               +
|                                                               |
+                Name (32 Bytes NULL terminated)                +
|                                                               |
+                                                               +
|                                                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                                                               |
+                                                               +
|                                                               |
+               Species (32 Bytes NULL terminated)              +
|                                                               |
+                                                               +
|                                                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+            Description (256 Bytes NULL terminated)            +
|                Diagram Truncated for space...                 |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+                                                               +
|                                                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

Note: All values are assumed to be in host-endian.

`protocol "Severity:8,Name Len:8,Species Len:8,PADDING:24,Description Length:16,Name (32 Bytes NULL padded and NULL terminated):128,Species (32 Bytes NULL padded and NULL terminated):128,Description (256 Bytes NULL padded and NULL terminated) Diagram Truncated for space...:512"`

- Severity level (can be modified) - `uint8_t`
- Animal name length - `uint8_t`
- Species name length - `uint8_t`
- PADDING - 3 x `uint8_t`
- Description length - `uint16_t`
- Animal name (cannot be modified) - 32-byte NULL terminated string
- Species name (cannot be modified) - 32-byte NULL terminated string
- Description of illness or injury (can be modified) - 256-byte NULL terminated string
