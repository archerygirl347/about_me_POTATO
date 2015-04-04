const int testLength = 13;
String questions[testLength];
String answers[testLength];
int score;
String name;

void setup(){
 
  Serial.begin(9600);
  score = 0;
  //change these to your own questions and name
  name = "Alexis Galon";
  questions[0] = "What is my favorite thing to do?";
  questions[1] = "What is my favorite vegetable?";
  questions[2] = "What hobbies do I like to do?";
  questions[3] = "What is my favorite color?";
  questions[4] = "On a scale of 1-10 how crazy are my siblings?";
  questions[5] = "How many siblings do I have?";
  questions[6] = "On a day off I like to be____?";
  questions[7] = "What month is my birthday?";
  questions[8] = "I LOVE school… true or false?";
  questions[9] = "My favorite type of music is___?";
  questions[10] = "I was in First Lego ______...";
  questions[11] = "My two most favorite bands of all time are ____?";
  questions[12] = "Name my friend who is a gamer and a turtle… TURTLE.";
  
  

  answers[0] = "eat";
  answers[1] = "potatoes";
  answers[2] = "archery and ballet";
  answers[3] = "aquamarine";
  answers[4] = "99999999999";
  answers[5] = "4";
  answers[6] = "lazy";
  answers[7] = "August";
  answers[8] = "false";
  answers[9] = "alternative";
  answers[10] = "League";
  answers[11] = "Fall Out Boy and Panic! at the Disco";
  answers[12] = "Gaurav";
  
  Serial.println("Hello this is " + name + "'s about me quiz.");
}

void loop(){
  Serial.println("********************");
  int index = 0;
  char character;
  String userAnswer;
  
  //while we have questions left
  while(index < testLength){
    userAnswer = "";
    Serial.flush();
    //print question
    Serial.println(questions[index]);
    //wait for user input
    while(!Serial.available());
    //read input
    while(Serial.available()) {
      character = Serial.read();
      userAnswer.concat(character);
      delay(100);
    }
    if( userAnswer == answers[index] ){
      Serial.println("Aha wise one...");
      score = score + 1;
      Serial.println("Your score is ");
      Serial.println(score);
    }
    else {
      Serial.println("FAIL...SPUDS CAN DO BETTER");
      Serial.println("The answer was...");
      Serial.println(answers[index]);
    }
    index = index + 1;
  }

}
