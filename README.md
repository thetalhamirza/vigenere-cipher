# Vigenere Cipher

I coded this in C, there were some complications but it turned out well.

I swear I'll make a decryptor soon :)<br>
.<br>
.<br>
.<br>
.<br>
.<br>
.<br>
.<br>
.<br>

## How it works

Substitution ciphers replace an alphabet with another based on a fixed or a
variable rule. One of the most famous substitution ciphers is the Vigenère cipher.
Vigenère cipher requires a Key to encrypt the text. A key can be any word or
phrase that is repeated until the whole plain text is covered. 
Let's suppose our Plain text is:
“Quanvolutional Neural Networks”
And the Key is:
“Qubits”
We will first Map the Key onto our Plain text like this:
![image](https://github.com/user-attachments/assets/8f8d08d4-e392-4b7f-aee7-17e04117436b)

We will then figure out the underlying decimal value of all the characters:
(space = 20)
![image](https://github.com/user-attachments/assets/8513348e-9afa-4483-9406-f5bd0f1f30c2)

Subtract 64 from each value:
(ignore subtraction for space value)
![image](https://github.com/user-attachments/assets/c170c092-f9de-4701-ab4c-eae77ab072ef)

Add the values vertically:
![image](https://github.com/user-attachments/assets/89d17a31-6127-4ace-ae6c-9435743c8074)

Take their modulo by 26 (i.e. (32 mod 26) = 6 )
![image](https://github.com/user-attachments/assets/2e6af908-c1ac-41f6-9466-71b90e46599f)

Add 64 :
![image](https://github.com/user-attachments/assets/1231beca-c087-4768-84d6-ea95786750f4)

Convert the values back to their Character Representation:
![image](https://github.com/user-attachments/assets/2046d2dd-4f41-4812-a3d0-3198eff85043)

Finally, Our Ciphertext would be :
“HPCWPHCPVRIGRGVWYNIVNCHXKRQAE”
