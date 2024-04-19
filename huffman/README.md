
 
# Huffman compressor
 @author Erik Sundin
 @since 2023-02-26
 
 ## Introduction
 This is a program for encoding and decoding textfiles using huffman encoding.
 
 ## Usage
 The program can be run with one of two flags. Either -encode or -decode. \n 
 And uses 3 input files like the following: \n
 USAGE:  huffman [OPTION] [FILE0] [FILE1] [FILE2]
 
 FILE0 is the file used for frequency analysis. \n
 FILE1 is the file to encode/decode. \n
 FILE2 is the output file. \n
 
 ## Analysis Frequency analysis
 
 The input file used for frequency analysis can be any UTF-8 textfile. \n
 Note that a larger text file whose characters are in the file to be encoded provides a more efficient \n 
 compression and the resulting output file will thus be smaller.
 
 ### Files
 
 The input file for frequency analysis cannot contain the character for EOT \n
 since it's being used by the program as a stop point. \n
 The files can only be so large that it fits in memory. \n
 FILE0 and FILE1 can be the same while encoding.
 
 ### Compilation
 The program can be compiled with the the line: \n
 gcc  -g huffman.c trie.c list.c pqueue.c htable.c freq_table.c bit_buffer.c encode_decode.c 
 
 
 ## Dependecies
 The program expects these to be installed:
 
 #### For compiling
 - GCC 
 - Make
 
 
 ### Encode
 The -encode flag encodes FILE1 according to frequence analysis done on FILE0 and stores the result in FILE2 \n
 Example of this can be shown in Figure 1.
 
 @image html https://i.imgur.com/UtsqA7N.png "Figure 1: Encode"  width=800
 
 In this example we run the program using the -encode flag. \n
 We use löremipsum.txt for frequency analysis and then we encode \n
 the file liten.txt. The result is then stored in out.txt.
 
 ### Decode
 The -decode flag decodes FILE1 according to frequence analysis done on FILE0 and stores the result in FILE2
 
 Example of this can be shown in figure 2.
 
 @image html https://i.imgur.com/6Wpeguv.png "Figure 2: Decode" width=800
 
 Here we use the same frequency files as in Figure 1 to decode the file out.txt. \n
 We then store the resulting file in decoded.txt \n
 @{
 
