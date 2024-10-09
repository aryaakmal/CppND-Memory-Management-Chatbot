#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    //std::cout << "GraphNode Constructor" << std::endl;
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //std::cout << "GraphNode Destructor" << std::endl;
    //delete _chatBot; //no reason to deallocate here

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    std::cout << "Here4.1\n";
    _chatBot = std::move(chatbot);
    std::cout << "Here4.2\n";
    _chatBot.SetCurrentNode(this);
    std::cout << "Here4.3\n";
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}
