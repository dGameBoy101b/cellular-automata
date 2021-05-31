#pragma once

#include <vector>

namespace Data
{
    template <class dataT>
    class TreeNode
    {
        public:
            /**
             * @brief Default constructor
             */
            TreeNode();
            /**
             * @brief Default destructor
             */
            ~TreeNode();
            /**
             * @brief Get the pointer to the parent of this tree node.
             * @return The pointer to the parent of this tree node.
             */
            const TreeNode<dataT&>* getParent() const;
            /**
             * @brief Set the parent node of this tree node.
             * @param parent The pointer to the new parent node.
             */
            void setParent(const TreeNode<dataT&>& parent);
            /**
             * @brief Get the vector of node that are the children of this tree node.
             * @return The list of nodes that are the children of this tree node.
             */
            const std::vector<TreeNode<dataT&>&>& getChildren() const;
            /**
             * @brief Add a child node to this tree node.
             * @param The tree node to add as a child of this tree node.
             */
            void addChild(TreeNode<dataT&>& child);
			/**
			 * @brief Get the data contained in this tree node.
			 * @return The data contained in this tree node.
			 */
			const dataT& getData() const;
			/**
			 * @brief Set the data contained in this tree node.
			 * @param data The data to contain in this tree node.
			 */
            void setData(const dataT& data);
            /**
             * @brief Calculate a readonly preiterator for this tree.
             * @return A readonly preiterator for this tree.
             */
            const std::vector<const TreeNode<dataT&>&>::const_iterator calcPreIterator() const;
            /**
             * @brief Calculate a readonly postiterator for this tree.
             * @return A readonly postiterator for this tree.
             */
            const std::vector<const TreeNode<dataT&>&>::const_iterator calcPostIterator() const;
            /**
             * @brief Calculate a preiterator for this tree.
             * @return A preiterator for this tree.
             */
            const std::vector<TreeNode<dataT&>&>::iterator calcPreIterator();
            /**
             * @brief Calculate a postiterator for this tree.
             * @return A postiterator for this tree.
             */
            const std::vector<TreeNode<dataT&>&>::iterator calcPostIterator();
        private:
            /**
             * @brief The parent node of this tree node.
             */
            TreeNode<dataT&>* parent;
            /**
             * @brief The children nodes of this tree node.
             */
            std::vector<TreeNode<dataT&>&>& children;
            /**
             * @brief The additional data this tree node contains.
             */
            dataT& data;
    };
}
