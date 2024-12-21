# CMP_SC 3050 FS2024

# Assignment 2: Implement Heap Sort

## Description

You are to implement Heap Sort as a function similar to the Standard C
Library's qsort function. This is similar to the way you implemented
Insertion Sort in A1.

You are given a main() program, a Makefile, a library, and some starter
code for your sorting function. All you need to do is complete the
actual code for the function heapsort() in the provided sort.c file.
However, I would suggest that you break heapsort() down by writing
worker functions as well, similar to the pseudocode provided in class.

## How to Get Started

The starter code is publicly available on GitHub. You can clone it using
git via the following command:

> git clone https://github.com/angrynarwhal/cs3050fs2024a2 

I recommend you clone this code somewhere under your home directory on
tc.rnet.missouri.edu. You are welcome to clone this and work on your
code on any platform you like. However, you should be aware that
submissions will **[[only]{.underline}]{.mark}** be evaluated by the TAs
on Hellbender. If, for example, something works on your
machine but doesn't compile on Hellbender, you will get a
zero.

Once you have cloned things down, you should cd to the newly cloned
directory and type "make". This will build the code and leave you with
an executable file called "mysort". The mysort program should work for
quick sort. However, you must implement heap sort (out of the box, this
sort will do nothing).

## Notes

-   You should not need to change any of the files except sort.c. When
    you have completed the assignment, submit only sort.c on Canvas. The
    TAs will clone fresh starter code down and copy in your sort.c in
    order to evaluate it.

-   Notice that the function you are writing is already prototyped in
    sort.h and an empty stub is available in sort.c.

-   If you want to swap the positions of two items in your data
    structure, you **[[must]{.underline}]{.mark}** use the provided
    Swap() function to do this. This is similar to your use of this
    function in the previous assignment.

-   If you want to assign one item to another (not swap them), you
    **[[must]{.underline}]{.mark}** use the Copy() function from
    cs3050.h. This will work whether your item is an int, a float, a
    struct, or whatever.

-   Notice that the tests try each function with a two int arrays and an
    array of structures (Customers). The Customer array is to be sorted
    first by lastname, firstname and then it is sorted again by age. The
    large int array does not show output (only counts of the compares
    and such) because it has approximately 10 million items in the
    array.

-   You don't need to worry about writing a Compare() function, as an
    appropriate one will be passed to you during testing. If you find it
    hard to think about how Compare() works, you might look at the
    Standard C Library function strcmp(). That function compares two
    strings and is an example of a Compare() function. A specific
    Compare() function must be used to allow the sort functions to
    compare elements of specific types (i.e., strcmp() knows how to
    compare strings, but you would need something else to compare ints,
    floats, structs, etc.).

-   You can certainly add your own functions to sort.c to break the
    problem down more. There should not be a need to add prototypes to
    sort.h.

## Sample Output

jimr@jimrsurfacepro9:\~/CS3050/SP2024/assignments/A2\$ ./mysort

Heap Sort:

\-\-\-\-\-\-\-\-\-\-\-\-\--

\*\*\*\*\* Small int array:

-\> 9 items: 23 -1 15 700 10 1 2 3 -99

-\> 9 items: -99 -1 1 2 3 10 15 23 700

\*\* Comparisons = 43, Swaps = 25 \*\*

\*\*\*\*\* Small Customer array:

-\> 10 items: Jim Ries (56), Larry Ries (54), Robert Bisby (56), Cisco
Ries (13), Albert Pujols (42), Adam Wainwright (40), Yadier Molina (39),
David Polly (56), Bill Moser (54), Neil Blanck (53),

-\> 10 items: Robert Bisby (56), Neil Blanck (53), Yadier Molina (39),
Bill Moser (54), David Polly (56), Albert Pujols (42), Cisco Ries (13),
Jim Ries (56), Larry Ries (54), Adam Wainwright (40),

\*\* Comparisons = 54, Swaps = 33 \*\*

-\> 10 items: Cisco Ries (13), Yadier Molina (39), Adam Wainwright (40),
Albert Pujols (42), Neil Blanck (53), Bill Moser (54), Larry Ries (54),
Jim Ries (56), David Polly (56), Robert Bisby (56),

\*\* Comparisons = 54, Swaps = 33 \*\*

\*\*\*\*\* Very Large Int array:

-\> 10485760 items:

461373440

-\> 10485760 items:

\*\* Comparisons = 469803914, Swaps = 238932644 \*\*

Quick Sort:

\-\-\-\-\-\-\-\-\-\-\-\-\--

\*\*\*\*\* Small int array:

-\> 9 items: 23 -1 15 700 10 1 2 3 -99

-\> 9 items: -99 -1 1 2 3 10 15 23 700

\*\* Comparisons = 19, Swaps = 0 \*\*

\*\*\*\*\* Small Customer array:

-\> 10 items: Jim Ries (56), Larry Ries (54), Robert Bisby (56), Cisco
Ries (13), Albert Pujols (42), Adam Wainwright (40), Yadier Molina (39),
David Polly (56), Bill Moser (54), Neil Blanck (53),

-\> 10 items: Robert Bisby (56), Neil Blanck (53), Yadier Molina (39),
Bill Moser (54), David Polly (56), Albert Pujols (42), Cisco Ries (13),
Jim Ries (56), Larry Ries (54), Adam Wainwright (40),

\*\* Comparisons = 23, Swaps = 0 \*\*

-\> 10 items: Cisco Ries (13), Yadier Molina (39), Adam Wainwright (40),
Albert Pujols (42), Neil Blanck (53), Bill Moser (54), Larry Ries (54),
Robert Bisby (56), David Polly (56), Jim Ries (56),

\*\* Comparisons = 23, Swaps = 0 \*\*

\*\*\*\*\* Very Large Int array:

-\> 10485760 items:

115343360

-\> 10485760 items:

\*\* Comparisons = 124780544, Swaps = 0 \*\*
