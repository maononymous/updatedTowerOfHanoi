# updatedTowerOfHanoi

## Problem statement
- There are 14 blocks given namely a,b,c,d,e,f,g,h,i,j,k,l,m,n which are stacked on each other in two given locations - L1 and L2.
- You are given two mechanical arms which can perform picking up a block and putting it down in a specified location.
- These arms can operate with only one block at a time.
- The initial states and final states of the locations are given as input.
- This program follows a particular procedure to get from initial states of the locations to the final states of the locations.
### Note:
The number of blocks is not fixed, it can be changed depending on the requirements. Minute changes in the code required for it.

## The Proposed Solution

### Algorithm
- The algorithm is divided in two phases. In Phase 1 -
  - Using both the arms, all the blocks in Location L1 are unstacked while searching for bottom-most block in the final state of L1.
  - If it is found, then it is held in the same arm by which it is found and with the other arm, location L1 is emptied.
  - If not found, then it is searched in location L2 by ustacking elements from L2 and stacking them in L1.
  - And once it is found, all the other blocks are put back into the location L2, and the found block is placed in L1 accordingly.
  - This same procedure is followed to arrange all the blocks in location L1.
- In Phase 2 -
  - Now that the blocks in location L1 are arranged according to their final state and L1 is in its order, we can arrange the blocks in location L2 to reach its final state.
  - For arranging blocks in L2, we follow the same procedure of how we arranged blocks in L1. 
  - The difference here is we use L1 for searching the block to be placed at each iteration by shifting all the blocks in L2 to L1.
  - This won't disturb the blocks we arranged in L1, as we will not be accessing those blocks.
  - The order of those blocks arranged in location L1 won't get disturbed.

### Functions used
The functions written in the program are -

#### pickUp()
This function takes two integer parameters - arm,loc. It has the return type VOID. If the value of arm is 1, then it uses arm1. If the value of arm is 2, then it uses arm2. If the value of loc is 1, then arm is used on L1. If the value of loc is 2, then arm is used on L2. The last element is removed from the given specific loc array and that value is stored in the given specific arm.

#### putDown()
This function takes two integer parameters - arm,loc. It has the return type VOID. If the value of arm is 1, then it uses arm1. If the value of arm is 2, then it uses arm2. If the value of loc is 1, then arm is used on L1. If the value of loc is 2, then arm is used on L2. The element from the given specific arm is removed and it is stored as the last element of the given specific loc.

#### inputFun()
This function is used for receiving the input from the user. It takes inputs of Initial and Final States of locations L1 and L2 as string. Then it converts the strings into char arrays and fills the values in the variables l1,l1e,l2,l2e.

#### printFun()
This function is used for printing the current states of the Locations L1 and L2.

#### arrangeBlocks()
This functions contains the whole working of the program. Once the inputs are taken, this function is invoked. The algorithm is implemented using the functions pickUp() and putDown() functions in a loop and the printFun() function is called at the end of each iteration to print the current states of the locations at the end of each iteration. By this, the movements of the blocks can be seen for each iteration.
