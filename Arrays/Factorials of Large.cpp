class Solution {
	public:
	
	vector<int> factorial(int n)
	{
		vector<int> ans(1, 1);
		
		while (n>1)
			{
			
			int carry = 0;
			int product;
			int size = ans.size();
			
			for (int i = 0; i<size; i++)
				{
				product = ans[i]*n + carry;
				
				ans[i] = product%10;
				
				carry = product/10;
			}
			
			while (carry)
				{
				ans.push_back(carry%10);
				carry /= 10;
			}
			
			n--;
		}
		
		reverse(ans.begin(), ans.end());
		return ans;
	}
};



/*
Approach:

1. Factorial ka result bohat bara ho sakta hai, is liye hum usay normal int data type mein store nahi kar sakte.

2. Long Long aik option hai, lekin uski bhi apni storage limit hoti hai. Large factorials ke liye ye bhi sufficient nahi hai.

3. Isi liye hum Vector use karenge, jisme factorial ke har digit ko separately store kar sakte hain.

4. Sab se pehle aik vector banayenge aur usmein 1 store karenge, kyunke factorial ki calculation 1 se start hoti hai.

   vector<int> result = {1};

5. Outer For Loop:

   for (int i = 2; i <= n; i++)

   Is loop ka kaam 2 se n tak har number ko current factorial ke saath multiply karna hai.

   Agar n = 5 hai toh:

   - Initially result = 1
   - i = 2 -> result * 2 = 2
   - i = 3 -> result * 3 = 6
   - i = 4 -> result * 4 = 24
   - i = 5 -> result * 5 = 120

   Yani outer loop decide karta hai ke current factorial ko kis number se multiply karna hai.

6. Inner For Loop:

   for (int j = 0; j < result.size(); j++)

   Vector mein factorial ke digits reverse order mein store hote hain.

   Example:

   result = {4, 2, 1};

   Ye asal mein 124 ko represent karta hai.

   Ab agar isay 3 se multiply karna ho toh vector ke har digit ko individually multiply karna padega.

   - j = 0 -> 4 ko multiply karenge.
   - j = 1 -> 2 ko multiply karenge.
   - j = 2 -> 1 ko multiply karenge.

   Isi liye inner loop use hota hai.

7. Carry:

   int carry = 0;

   Multiplication ke dauran agar result 10 ya us se bara aaye toh extra value ko carry mein store karte hain.

   Example:

   4 * 5 = 20

   - 20 % 10 = 0 -> Current digit.
   - 20 / 10 = 2 -> Carry.

   Agli digit ki multiplication mein ye carry add kar diya jata hai.

8. While Loop:

   while (carry > 0)

   Ye loop tab chalta hai jab vector ke saare existing digits multiply ho chuke hon, lekin carry abhi bhi baqi ho.

   Example:

   99 * 9 = 891

   Reverse order mein initial vector:

   {9, 9}

   Multiplication:

   - First digit: 9 * 9 = 81
     - Digit = 1
     - Carry = 8

   - Second digit: 9 * 9 + 8 = 89
     - Digit = 9
     - Carry = 8

   Ab vector {1, 9} hai aur carry 8 bach gaya.

   While loop is remaining carry ko vector mein add karega.

   Final vector:

   {1, 9, 8}

   Yani 891!

9. Reverse:

   reverse(result.begin(), result.end());

   Humne calculation ke dauran digits reverse order mein store kiye the taake multiplication easily kar saken.

   Is liye end mein reverse() use karenge taake digits correct order mein aa jayen.

10. Finally, updated vector return kar denge.

*/
