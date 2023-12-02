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

std::pair<std::optional<std::string>, bool> CommandTrieNode::findFirstMatch(const std::string &command, const bool &executeFunction)
{
/// FOR NOW EXECUTEFUNCTION IS NOT USED! IMPLEMENT USING LAMBDA IN NODE

    std::shared_ptr<CommandTrieNode> currentNode = shared_from_this();
    for (int i = 0; i < command.length(); i++) {

        currentNode = currentNode->getChildNode(command[i]);

        if (currentNode == nullptr);
   //         return false;
    }

   // return currentNode->isEndOfWord;

}


