using System;
using System.IO;
using System.Net;
using System.Security.Cryptography.X509Certificates;
using System.Text.RegularExpressions;

namespace Round
{
    class Round
    {
	public static void Run(string code)
        {
            Dictionary<string, dynamic> variables = RoundParser.Parse(code);
			// string functionPattern = @$"\s*(\w+)\((.*)\)";
			foreach (var line in code.Split("\n"))
            {
                Console.WriteLine(line);
            }
        }
        public static void RunFunction(string functionName, string? parameters)
        {
            switch (functionName)
            {
                case "print":
		    Console.WriteLine(parameters);
		    break;
            }
        }
    }
    class RoundParser
    {
        public static Dictionary<string, dynamic> Parse(string code)
	{
	    string stringPattern = "(?:\\\"|\\\')(.*)(?:\\\"|\\\')";
	    // variablePattern groups explaination:
	    /* First: catches variable name (one or more alphanumeric and underscore characters)
	     * Second: catches type, like 'var_name: string'... This one is optional
	     * Third: gets the string, integer or float in it*/
	    string variablePattern = @$"(\w+):\s*(string|int|float)\s*=\s*({stringPattern}|\d+|\d+\.\d+)";

	    MatchCollection getVariables = Regex.Matches(code, variablePattern);
	    Dictionary<string, dynamic> variables = [];
	    foreach (Match match in getVariables)
            {
                variables.Add(match.Groups[1].Value, match.Groups[3].Value);
            }
	    return variables;
	}
    }
    class Program
    {
	static void Main(string[] args)
	{
	    string roundFile = args.Length > 0 ? File.ReadAllText(args[0]) : "";
	    // Console.WriteLine(roundFile);
			
	    Round.Run(roundFile);
	}
    }
}
