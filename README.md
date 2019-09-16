# Extended soundex kata

Here we start with the soundex example from before. The task is to test-drive the implementation
of more features. 

1. Develop a console application that takes an author's name on the command line and prints out the soundex encoded string.
2. Extend the application so that it can take further inputs, stopping when an empty string is entered.
3. Customer support would like logs of each query that is made. Extend the soundex object to be able to send such logs to (say) the console output or a file.
4. The logger just developed may throw an exception. In that case, support would like the error sent to an alternative location, such as a database or a webservice. 