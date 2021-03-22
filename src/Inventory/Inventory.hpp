
template<class T>
class Inventory
{
    private:
        T** elements;
        int numOfElement;
    public:
        Inventory()
        {
            elements = NULL;
            numOfElement = 0;
        }

        ~Inventory()
        {
            delete[] elements;
        }

        T& operator[](int idx)
        {
            return *elements[idx];
        }

        void add(T& elmt)
        {
            T** temp = new T*[numOfElement+1];
            for(int i = 0; i < numOfElement; i++)
            {
                temp[i] = elements[i];
            }
            temp[numOfElement] = &elmt;
            delete[] elements;
            elements = temp;
            numOfElement++;
        }

        void delAt(int idx)
        {
            if(numOfElement == 0)
            {
                //throw empty
            }
            T** temp = new T*[numOfElement-1];
            for(int i = 0; i < idx; i++)
            {
                temp[i] = elements[i];
            }
            for(int i = idx; i < numOfElement-1; i++)
            {
                temp[i] = elements[i+1];
            }
            delete[] elements;
            elements = temp;
            numOfElement--;
        }

        int getNumOfElement()
        {
            return numOfElement;
        }
};