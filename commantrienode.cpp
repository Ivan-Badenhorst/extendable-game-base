#include "commantrienode.h"

CommandTrieNode::CommandTrieNode()
{

}

void CommandTrieNode::insert(const std::string &command)
{

    std::shared_ptr<CommandTrieNode> currentNode = shared_from_this();

    for (int i = 0; i < command.length(); i++) {
        char letter = command[i];

        /* make a new node if there is no path */
        if (currentNode->noChildNode(letter))
            currentNode->insertChildNode(letter);
            //currentNode->map[letter] = getNewTrieNode();

        currentNode = currentNode->getChildNode(letter);
    }

    currentNode->setEndOfCommand(true);

}

bool CommandTrieNode::noChildNode(const char &letter) const
{
    return (childNodes.find(letter) == childNodes.end());
}

void CommandTrieNode::insertChildNode(const char &letter)
{
    childNodes[letter] = std::make_shared<CommandTrieNode>();
}

std::shared_ptr<CommandTrieNode> CommandTrieNode::getChildNode(const char &letter) const
{
    return childNodes.find(letter)->second;
}

void CommandTrieNode::setEndOfCommand(const bool &val)
{
    isEndOfCommand = val;
}

std::pair<std::optional<std::string>, int> CommandTrieNode::findFirstMatch(const std::string &command, const bool &executeFunction)
{
    /*  int in the pair can be 0, 1, 2, or 3:
        *      0 -> no return string and there is no command starting with this command paramter     XXXX
        *      1 -> the string returned is a command, and there are no other commands starting with the returned string
        *      2 -> the string returned is not a command, but there are other commands starting with the returned string
        *      3-> the string returned is a command, and there are other commands starting with the returned string
    */
    std::shared_ptr<CommandTrieNode> currentNode = shared_from_this();
    for (int i = 0; i < command.length(); i++) {

        currentNode = currentNode->getChildNode(command[i]);

        if (currentNode == nullptr){
            std::optional<std::string> fullFirstMatch;
            auto returnInt = 0;
            return std::make_pair(fullFirstMatch, returnInt); //no return string and there is no command starting with this command paramter
        }

    }


    auto isUniqueCommand = currentNode->getIsEndOfCommand();
    std::optional<std::string> fullFirstMatch = command; //only adjust this value if isCommand = false!!!!

    if(currentNode->getNumChildren() == 0){
        auto returnInt = 1;
        return std::make_pair(fullFirstMatch, returnInt);//the string returned is a command, and there are no other commands starting with the returned string
    }
    else if(currentNode->getNumChildren() > 1){
        if(isUniqueCommand){
            auto returnInt = 3;
            return std::make_pair(fullFirstMatch, returnInt);
        }
        else{
            auto returnInt = 2;
            return std::make_pair(fullFirstMatch, returnInt);
        }
    }
    else if(isUniqueCommand){
        auto returnInt = 3;
        return std::make_pair(fullFirstMatch, returnInt);
    }


    //now we are in the case that we 1 children and the input command is not a unique command!!

    //need a function to get this only child!!!
    fullFirstMatch.value() += currentNode->getChildNodes().begin()->first; // add the letter to the back of my return
    currentNode = currentNode->getChildNodes().begin()->second;


    //loop through and stop either at split, or at end of command!!
    while(currentNode->getNumChildren() > 0){
        //first I need to get the next node


        if(currentNode->getNumChildren() > 1){//we have a split
            auto returnInt = 2;
            if(currentNode->getIsEndOfCommand()){
                returnInt = 3;
            }
            return std::make_pair(fullFirstMatch, returnInt);
        }
        else if(currentNode->isEndOfCommand){
            auto returnInt = 3;
            return std::make_pair(fullFirstMatch, returnInt);
        }
        //here we know it has only 1 child
        fullFirstMatch.value() += currentNode->getChildNodes().begin()->first; // add the letter to the back of my return
        currentNode = currentNode->getChildNodes().begin()->second;

    }

   // fullFirstMatch.value() += currentNode->getChildNodes().begin()->first; // add the letter to the back of my return
    auto returnInt = 1;
    return std::make_pair(fullFirstMatch, returnInt);

}

int CommandTrieNode::getNumChildren() const
{
    return childNodes.size();
}

bool CommandTrieNode::getIsEndOfCommand() const
{
    return isEndOfCommand;
}

std::unordered_map<char, std::shared_ptr<CommandTrieNode> > CommandTrieNode::getChildNodes() const
{
    return childNodes;
}


