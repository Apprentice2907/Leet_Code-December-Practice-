// Given a date string in the form Day Month Year, where:

// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:

// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.
 

// Example 1:

// Input: date = "20th Oct 2052"
// Output: "2052-10-20"
// Example 2:

// Input: date = "6th Jun 1933"
// Output: "1933-06-06"
// Example 3:

// Input: date = "26th May 1960"
// Output: "1960-05-26"






// My approach using map and string manipulation

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> monthMap = {
            {"Jan", "01"}, 
            {"Feb", "02"}, 
            {"Mar", "03"}, 
            {"Apr", "04"},
            {"May", "05"}, 
            {"Jun", "06"}, 
            {"Jul", "07"}, 
            {"Aug", "08"},
            {"Sep", "09"}, 
            {"Oct", "10"}, 
            {"Nov", "11"}, 
            {"Dec", "12"}
        };
        
        string word;
        stringstream ss(date);
        vector<string> result;

        while (ss >> word) {
            result.push_back(word);
        }

        string day = "";
        for (char c : result[0]) {
            if (isdigit(c)) day += c;
        }
        if (day.size() == 1) day = "0" + day;  

        string month = monthMap[result[1]];  
        string year = result[2];             

        return year + "-" + month + "-" + day;
    }
};










// Optimal solution using map and multiple string manipulation

class Solution {
    string month(string m){
        if(m == "Jan") return "01-"; 
        if(m == "Feb") return "02-"; 
        if(m == "Mar") return "03-"; 
        if(m == "Apr") return "04-"; 
        if(m == "May") return "05-"; 
        if(m == "Jun") return "06-"; 
        if(m == "Jul") return "07-"; 
        if(m == "Aug") return "08-"; 
        if(m == "Sep") return "09-"; 
        if(m == "Oct") return "10-"; 
        if(m == "Nov") return "11-"; 
        if(m == "Dec") return "12-";
        return "false";  
    }
public:
    string reformatDate(string& date) {
        const int n = date.size();

        date += "-"+ month(date.substr(n-8,3));
        if(date[1] >= '0' && date[1] <= '9')
            date += date.substr(0,2);
        else
            date += "0"+date.substr(0,1);

        return date.substr(n-4);
    }
};

