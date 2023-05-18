void add_to_vector(vector<int> &A,int x)
{
	A.push_back(x);
}

/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int> &A)
{
    sort(A.begin(), A.end());
}

/*reverses the vector A*/
void reverse_vector(vector<int> &A)
{
	vector<int> a;
	for(auto i=A.rbegin(); i!=A.rend(); ++i){
	    a.push_back(*i);
	}
	A.swap(a);
}

/*returns the size of the vector  A */
int size_of_vector(vector<int> &A)
{
	return A.size();
}

/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<int> b;
	for(auto i=A.rbegin(); i!=A.rend(); ++i){
	    b.push_back(*i);
	}
	A.swap(b);
    
}

/*prints space separated 
elements of vector A*/
void print_vector(vector<int> &A)
{
	for(auto i=A.begin(); i!=A.end(); i++)
	{
	    cout<<*i<<" ";
	}
}