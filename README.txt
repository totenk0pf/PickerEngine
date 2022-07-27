I. INSTRUCTIONS
1. Extract the zip file.
2. You can either run the built binary in the Release folder, or build the solution yourself as a .sln file has been included.
3. The two following files must be in the same directory as the binary, or the engine won't launch:
+) picker-test-data.json
+) wolf-sans.ttf
NOTE: If you are testing from the solution file, make sure to modify the picker-test-data.json file found within the project folder to see changes.

--
II. HOW TO PLAY 
1. You are given a maximum amount of picks to select items on the board.
2. Left click on a card to select it.
3. Once your pick amount has reached 0, you can no longer pick any items.
4. Press "H" to reset the game.

--
III. DATA MODIFICATION
The engine parses all data from the included .json file, and the format has been modified to accommodate extra variables:
It has been divided into two sections:

1. Items:
Items can be added or removed here using the following format:
{
    "id": "ID",
    "name": "Name",
    "weight": 1,
    "score": 0
}

where:
    "id" is the unique identifier for the item,
    "name" is the display name of the item,
    "weight" is the distribution weight for item. Items with a higher weight spawn more frequently. (float)
    "score" is the payout amount if the player lands on a tile with the item. (int)

2. Settings:
These are variables responsible for distribution and rendering of the items on the board:
"settings": {
    "pickCount": 2,
    "itemCount": 8,
    "itemPerRow": 4
}

where:
    "pickCount" is the number of turns in which players are allowed to pick an item.
    "itemCount" is the total amount of generated items on the board.
    "itemPerRow" is the maximum amount of item per generated row.

--
IV. CONTACT
If you encounter any bugs or have questions regarding the project, feel free to contact me at:
+) E-mail: nguyenhuuquang2608@gmail.com
+) Alternate e-mail: quang.nh@st.buv.edu.vn
+) Phone: +84 931 739 800