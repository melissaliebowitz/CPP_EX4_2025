//melissaliebowitz@yahoo.com
#include <iostream>
#include <vector>
#include <algorithm>

namespace container{

    template <typename T>

    class MyContainer{
        private:
        struct Node {
            T value;
            Node *next;
            Node(const T& v, Node *n = nullptr): value(v), next(n){}
        };

        Node *first;

        public:
        MyContainer(): first(nullptr){};

        ~MyContainer()
        {   
            Node *current = first;
            while (current)
            {
                Node *next = current->next;
                delete current;
                current = next;
            }
            
        }

        bool isEmpty() const
        {
            return first == nullptr;
        }

        void add(const T& s)
        {
            if (isEmpty())
            {
                first = new Node(s);
            } else{
                Node *temp = first;
                while (temp->next)
                {
                    temp = temp->next;
                }

                temp->next = new Node(s);
            }
        }

        void remove(const T& s)
        {
            if (isEmpty())
            {
                throw std:: runtime_error("No elements in container.");
            }

            bool found = false;
            //when we want to delete the first value
            while (first && first->value == s)
            {
                Node *del = first;
                first = first->next;
                delete del;
                found = true;
            }
            
            Node *temp = first;
            while (temp && temp->next)
            {   
                if (temp->next->value == s)
                {
                    Node *del = temp->next;
                    temp->next = temp->next->next;
                    delete del;
                    found = true;
                }
                else{
                temp = temp->next;
                }
            }

            if (!found)
            {
                throw std:: runtime_error("Element not found in container.");
            }
            
            
        }

        int size() const
        {   
            int counter = 0;
            Node *temp = first;
            while (temp)
            {
                ++counter;
                temp = temp->next;
            }
            
            return counter;
        }

        void print() const
        {
            Node *temp = first;
            std:: cout << "[" ;
            while (temp)
            {
                std:: cout << temp->value;
                if (temp->next)
                {
                    std:: cout << ", ";
                }
                temp = temp->next;
            }
            std:: cout << "]" << std:: endl;
        }

        //iterator #1
        class AscendingOrder{
            private: 
                std:: vector<Node*> sorted_asc;
                size_t index;
            
            public:
                AscendingOrder(Node *head, bool hasEnd = false)
                {
                    while (head)
                    {
                        sorted_asc.push_back(head);
                        head = head->next;
                    }

                    std:: sort(sorted_asc.begin(), sorted_asc.end(), [](Node *a, Node *b){return a->value < b->value;});
                    index = hasEnd ? sorted_asc.size() : 0;
                    
                }

               T& operator*() const
               {
                    return sorted_asc[index]->value;
               }

               AscendingOrder& operator++()
               {
                    ++index;
                    return *this;
               }

               AscendingOrder operator++(int)
               {
                    AscendingOrder temp = *this;
                    ++(*this);
                    return temp;

               }

               bool operator==(const AscendingOrder& other) const
               {
                    return index == other.index;
               }

               bool operator!= (const AscendingOrder& other) const
               {
                    return index != other.index;
               }
        };

        //iterator #2
        class DescendingOrder{
            private:
                std:: vector<Node*> sorted_desc;
                size_t index;
            
            public:
                DescendingOrder(Node *head, bool hasEnd)
                {
                    while (head)
                    {
                        sorted_desc.push_back(head);
                        head = head->next;
                    }
                    
                    std:: sort(sorted_desc.begin(), sorted_desc.end(), [](Node *a, Node *b){return a->value > b->value;});
                    index = hasEnd ? sorted_desc.size() : 0;
                    
                }

                T& operator*() const
                {
                    return sorted_desc[index]->value;
                }

                DescendingOrder& operator++()
                {
                    ++index;
                    return *this;
                }

                DescendingOrder operator++(int)
                {
                    DescendingOrder temp = *this;
                    ++*this;
                    return temp;
                }

                bool operator==(const DescendingOrder& other)
                {
                    return index == other.index;
                }

                bool operator!=(const DescendingOrder& other)
                {
                    return index != other.index;
                }
        };

        //iterator #3
        class SideCrossOrder{
            private:
            std:: vector<T> elements;
            size_t index;

            public:
            SideCrossOrder(Node *head, bool hasEnd)
            {
                std:: vector<T> sorted_side;
                while (head)
                {
                    sorted_side.push_back(head->value);
                    head = head->next;
                }
                std:: sort(sorted_side.begin(), sorted_side.end());
                size_t left = 0;
                size_t right = sorted_side.size() -1;

                while(left <= right)
                {
                    elements.push_back(sorted_side[left++]);
                    if (left <= right)
                    {
                        elements.push_back(sorted_side[right--]);
                    }
                }

                index = hasEnd ? elements.size() : 0;
                
            }   

            T& operator*()
            {
                return elements[index];
            }

            SideCrossOrder& operator++()
            {
                ++index;
                return *this;
            }

            SideCrossOrder operator++(int)
            {
                SideCrossOrder temp = *this;
                ++*this;
                return temp;
            }

            bool operator==(const SideCrossOrder& other)
            {
                return index == other.index;
            }

            bool operator!=(const SideCrossOrder& other)
            {
                return index != other.index;
            }


        };

        //iterator #4
        class ReverseOrder{
            private:
            std:: vector<Node*> sorted_rev;
            size_t index;

            public:
            ReverseOrder(Node *head, bool hasEnd)
            {
                while (head)
                {
                    sorted_rev.push_back(head);
                    head = head->next;
                }

                index = hasEnd ? -1 : sorted_rev.size() - 1;
            }

            T& operator*() const
            {
                return sorted_rev[index]->value;
            }

            ReverseOrder& operator++()
            {   
                --index;
                return *this;
            }

            ReverseOrder operator++(int)
            {
                ReverseOrder temp = *this;
                --index;
                return temp;
            }

            bool operator==(const ReverseOrder& other)
            {
                return index == other.index;
            }

            bool operator!=(const ReverseOrder& other)
            {
                return index != other.index;
            }
        };

        //iterator #5
        class Order{
            private:
            Node *pointer_to_current;

            public:
            Order(Node *ptr): pointer_to_current(ptr){}

            T& operator*() const
            {
                return pointer_to_current->value;
            }

            Order operator++()
            {
                pointer_to_current = pointer_to_current->next;
                return *this;
                
            }

            Order operator++(int)
            {
                Order temp = *this;
                pointer_to_current = pointer_to_current->next;
                return temp;

            }

            bool operator==(const Order& other) const
            {
                return pointer_to_current == other.pointer_to_current;
            }

            bool operator!=(const Order& other) const
            {
                return pointer_to_current != other.pointer_to_current;
            }

        };

        //iterator #6
        class MiddleOutOrder{
            private:
                std:: vector<T> elements;
                size_t index;

            public:
            MiddleOutOrder(Node *head, bool hasEnd)
            {
                std:: vector<T> sorted;
                while (head)
                {
                    sorted.push_back(head->value);
                    head = head->next;
                }

                int r_middle = static_cast<int>(sorted.size() / 2);
                int l_middle = r_middle - 1;

                while(l_middle >= 0 || r_middle < static_cast<int>(sorted.size()))
                {   
                    if (r_middle < static_cast<int>(sorted.size()))
                    {
                        elements.push_back(sorted[r_middle++]);
                    }

                    if (l_middle >= 0)
                    {
                        elements.push_back(sorted[l_middle--]);
                    }
                }

                index = hasEnd ? sorted.size() : 0;
            }

            T& operator*()
            {
                return elements[index];
            }

            MiddleOutOrder operator++()
            {
                ++index;
                return *this;
            }

            MiddleOutOrder operator++(int)
            {
                MiddleOutOrder temp = *this;
                ++*this;
                return temp;
            }

            bool operator==(const MiddleOutOrder& other)
            {
                return index == other.index;
            }

            bool operator!=(const MiddleOutOrder& other)
            {
                return index != other.index;
            }


        };

               AscendingOrder begin_ascending_order()
               {
                return AscendingOrder{first};
               }

               AscendingOrder end_ascending_order()
               {
                    return AscendingOrder{first, true};
               }

               DescendingOrder begin_descending_order()
               {
                    return DescendingOrder{first, false};
    
               }

               DescendingOrder end_descending_order()
               {
                    return DescendingOrder{first, true};
               }

               SideCrossOrder begin_sidecross_order()
               {
                    return{first, false};
               }

               SideCrossOrder end_sidecross_order()
               {
                return{first, true};
               }

               ReverseOrder begin_reverse_order()
               {
                    return ReverseOrder{first, false};
               }

               ReverseOrder end_reverse_order()
               {
                    return ReverseOrder{first, true};
               }

               Order begin_order()
               {
                    return Order{first};
               }

               Order end_order()
               {
                    return Order{nullptr};
               }

               MiddleOutOrder begin_middle_order()
               {
                    return MiddleOutOrder{first, false};
               }

               MiddleOutOrder end_middle_order()
               {
                    return{first, true};
               }
    

    };

}