# Arithmetic-App

create an application to help first-graders master their arithmetic skills using natural numbers (addition, subtraction, multiplication, and division).  
-----------------------------------------------------------
The application should start with a menu that offers the following options:  
     o Generate a question  
     o Display results summary 
     o Display history  
     o Exit  
----------------------------------------------------------
Here is a description of each of the menu options:  
•[Generate a question] -->  This functionality creates a question by randomly selecting a value for the first operand, a value for the arithmetic operation, and a value for the second operand. Note for division, the second operand cannot be zero, and for subtraction, the second operand should be less than the first operand.   
    o You may restrict the value for first and second operands to be between 0 and 100.  
    o The application should allow the student to continue to try to answer the question until correct or until the student chooses to abort answering the question.  
-----------------------------------------------------------
• [Display results Summary] --> This functionality simply informs the student of the number of questions attempted for each arithmetic operation and the number of questions answered correctly.   
-----------------------------------------------------------
• [Display history] ---> This functionality will list each question given to the student, the number of tries, and whether the question was answered correctly or aborted.  
    o You must use the C++ STL list container to save the history.  
-----------------------------------------------------------
• [ Exit the application]   
-----------------------------------------------------------
Include the preprocessor directives (#ifndef, #define, #endif) to prevent a header file from being included (#include) multiple times, and Separate the class interface from the class implementation.    
-----------------------------------------------------------
