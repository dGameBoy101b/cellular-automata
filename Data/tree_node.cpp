#include "tree_node.h"

namespace Data
{
    TreeNode::TreeNode()
    {
        this->parent = nullptr;
        this->children = new std::vector<TreeNode<dataT&>&>();
        this->data = new dataT();
    }
    TreeNode::~TreeNode()
    {
        this->parent = nullptr;
    }
    TreeNode<dataT&>* TreeNode::getParent() const
    {
    	return this->parent;
    }
    void TreeNode::setParent(const TreeNode<dataT&>* parent)
    {
    	TreeNode<dataT&>* temp = this->parent;
    	this->parent = parent;
    	if (temp != nullptr)
		{
			for (std::vector<dataT>::const_iterator it = temp->children.begin(); it != temp->children.end(); it++)
			{
				if (it == this)
				{
					temp->children.erase(it);
					break;
				}
			}
		}
		if (this->parent != nullptr)
		{
			this->parent->children.push_back(*this);
		}
    }
    const std::vector<TreeNode<dataT&>&>& TreeNode::getChildren() const
    {
    	return this->children;
    }
    void TreeNode::addChild(TreeNode<dataT&>& child)
    {
    	for (std::vector<dataT&>::const_iterator it = this->children.begin(); it != this->children.end(); it++)
		{
			if (it == &child)
			{
				return;
			}
		}
		this->children.push_back();
		child.parent = this;
    }
    const dataT& TreeNode::getData() const
    {
    	return this->data;
    }
    void TreeNode::setData(const dataT& data)
    {
    	this->data = data;
    }
	const std::vector<const TreeNode<dataT&>&> calcPreIterator() const
	{
		std::vector<const TreeNode<dataT&>&> ls = new std::vector<TreeNode<dataT&>&>();
		std::vector<const TreeNode<dataT&>&> temp;
		ls.push_back(*this);
		for (std::vector<TreeNode<dataT&>&>::const_iterator it = this->children.begin(); it != this->children.end(); it++)
		{
			temp = it->calcPreIterator();
			for (std::vector<TreeNode<dataT&>&>::const_iterator t_it = temp.begin(); t_it != temp.end(); t_it++)
			{
				ls.push_back(*t_it);
			}
		}
		return ls;
	}
	const std::vector<const TreeNode<dataT&>&>: calcPostIterator() const
	{
		std::vector<const TreeNode<dataT&>&> ls = new std::vector<TreeNode<dataT&>&>();
		std::vector<const TreeNode<dataT&>&> temp;
		for (std::vector<TreeNode<dataT&>&>::const_iterator it = this->children.begin(); it != this->children.end(); it++)
		{
			temp = it->calcPreIterator();
			for (std::vector<TreeNode<dataT&>&>::const_iterator t_it = temp.begin(); t_it != temp.end(); t_it++)
			{
				ls.push_back(*t_it);
			}
		}
		ls.push_back(*this);
		return ls;
	}
	const std::vector<TreeNode<dataT&>&> calcPreIterator()
	{
		std::vector<TreeNode<dataT&>&> ls = new std::vector<TreeNode<dataT&>&>();
		std::vector<TreeNode<dataT&>&> temp;
		ls.push_back(*this);
		for (std::vector<TreeNode<dataT&>&>::const_iterator it = this->children.begin(); it != this->children.end(); it++)
		{
			temp = it->calcPreIterator();
			for (std::vector<TreeNode<dataT&>&>::const_iterator t_it = temp.begin(); t_it != temp.end(); t_it++)
			{
				ls.push_back(*t_it);
			}
		}
		return ls;
	}
	const std::vector<TreeNode<dataT&>&> calcPostIterator()
	{
		std::vector<const TreeNode<dataT&>&> ls = new std::vector<TreeNode<dataT&>&>();
		std::vector<const TreeNode<dataT&>&> temp;
		for (std::vector<TreeNode<dataT&>&>::const_iterator it = this->children.begin(); it != this->children.end(); it++)
		{
			temp = it->calcPreIterator();
			for (std::vector<TreeNode<dataT&>&>::const_iterator t_it = temp.begin(); t_it != temp.end(); t_it++)
			{
				ls.push_back(*t_it);
			}
		}
		ls.push_back(*this);
		return ls;
	}
}
