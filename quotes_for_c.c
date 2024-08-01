#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  char q[31][460];
  strcpy(q[0], " \"To live is to think.\" - Marcus Tullius Cicero ");
  strcpy(
      q[1],
      " \"Power tends to corrupt and absolute power corrupts absolutely. Great "
      "men are almost always bad men, even when they exercise influence and "
      "not authority; still more when you superadd the tendency of the "
      "certainty of corruption by authority.” - Lord Anton ");
  strcpy(q[2],
         " \"The difference between the novice and the master is that the "
         "master has failed more times than the novice has tried.\" "
         "-Korosensei (Anime: Assassination Classroom; Author: Yusei Matsui) ");
  strcpy(q[3], " \"It's human nature not to realize the true value of "
               "something unless they lose it.” – Orochimaru (Anime: Naruto) ");
  strcpy(q[4], " \"Wake up to reality! Nothing ever goes as planned in this "
               "world. The longer you live, the more you realize that in this "
               "reality only pain, suffering and futility exist.\" - Madara "
               "Uchiha (Anime: Naruto; Author: Masashi Kishimoto) ");
  strcpy(q[5], " \"Neque porro quisquam est qui dolorem ipsum quia dolor sit "
               "amet, consectetur, adipisci velit...\" <!--\"There is no one "
               "who loves pain itself, who seeks after it and wants to have "
               "it, simply because it is pain...\"--> ");
  strcpy(q[6], " \"জীবনে কি হইতে চাই? মানুষ হইতে চাই। বেশি উপরে উঠতে চাইনা, "
               "যাতে নিচের মানুষগুলোকে তুচ্ছ পিঁপড়ার মত দেখায়। বেশি নিচে নামতে "
               "চাইনা যাতে সবাই আমাকে পিঁপড়া ভেবে মাড়িয়ে দেয়। খুব ইচ্ছা আছে, "
               "একদিন নিজেকে মানুষ দাবী করবো।\" - রায়হান রাহী (NSTU) ");
  strcpy(q[7],
         " \"An idiot admires complexity, a genius admires simplicity, a "
         "physicist tries to make it simple, for an idiot anything the more "
         "complicated it is the more he will admire it if you make something "
         "so clusterfucked he can't understand it he's gonna think you're a "
         "god cause you made it so complicated nobody can understand it. "
         "That's how they write journals in Academics, they try to make it so "
         "complicated people think you're a genius” ― Terry Davis ");
  strcpy(q[8],
         " \"Anything can be a sword if you polish it enough.\" ~Shiota Nagisa "
         "(Anime: Assassination Classroom; Author: Yusei Matsui) ");
  strcpy(q[9],
         " \"As you go through life, the might current of society is bound to "
         "get in your way and there will certainly be times when things don't "
         "go as you'd hoped.\" -Koro-sensei (Anime: Assassination Classroom) ");
  strcpy(q[10], " \"The world will always be filled with injustice.\" "
                "-Koro-sensei (Anime: Assassination Classroom) ");
  strcpy(
      q[11],
      " \"When the student is ready, the teacher will appear. When the student "
      "is truly ready, the teacher will disappear.\" - well-known proverb ");
  strcpy(q[12],
         " \"We Act According To Our Own Sense Of Justice.\"; \"If You Don't "
         "Share Someone's Pain, You Can Never Understand Them.\" ");
  strcpy(
      q[13],
      " Don't just learn, experience. Don't just read, absorb. Don't just "
      "change, transform. Don't just relate, advocate. Don't just promise, "
      "prove. Don't just criticize, encourage. Don't just think, ponder. Don't "
      "just take, give. Don't just see, feel. Don't just dream, do. Don't just "
      "hear, listen. Don't just talk, act. Don't just tell, show. Don't just "
      "exist, live.” ― Roy T. Bennett, The Light in the Heart ");
  strcpy(q[14], " \"Success is not how high you have climbed, but how you make "
                "a positive difference to the world.” ― Roy T. Bennett, The "
                "Light in the Heart ");
  strcpy(q[15], " \"If you know the enemy and know yourself, you need not fear "
                "the result of a hundred battles. If you know yourself but not "
                "the enemy, for every victory gained you will also suffer a "
                "defeat. If you know neither the enemy nor yourself, you will "
                "succumb in every battle.”― Sun Tzu, The Art of War ");
  strcpy(q[16], " \"In the midst of chaos, there is also opportunity” ― "
                "Sun-Tzu, A Arte da Guerra ");
  strcpy(q[17],
         " \"To know your Enemy, you must become your Enemy.” ― Sun Tzu ");
  strcpy(q[18], " \"Appear weak when you are strong, and strong when you are "
                "weak.” ― Sun Tzu, The Art of War ");
  strcpy(q[19], " Make yourself necessary and you will always be needed. If "
                "you want to feel successful, learn to create, innovate, or "
                "design something other people can use and need. ");
  strcpy(q[20],
         " You never really lose until you stop trying. The words \"I can't” "
         "never accomplish anything. \"I'll try,” on the other hand, can "
         "perform wonders. Until you try you don't know what you can do. ");
  strcpy(q[21], " Rule your mind or it will rule you. When you rule your mind "
                "by controlling negativity and doubt, you rule your world. The "
                "choice is yours to make every day. ");
  strcpy(q[22],
         " All men can see these tactics whereby I conquer, but what none can "
         "see is the strategy out of which victory is evolved. - Sun Tzu ");
  strcpy(q[23], " The less men think, the more they talk. - Montesquieu; A "
                "woman simply is, but a man must become. - Camille Paglia ; "
                "\"A Man Who Cannot Command Himself Will Always Be a Slave.\" "
                "\"Wer sich nicht selbst befiehlt, bleibt immer Knecht.\" — "
                "Johann Wolfgang von Goethe, Zahme Xenien ");
  strcpy(q[24], " Give me six hours to chop down a tree and I will spend the "
                "first four sharpening the axe. - Abraham Lincoln ");
  strcpy(q[25],
         " I am not afraid of an army of lions led by a sheep; I am afraid of "
         "an army of sheep led by a lion. - Alexander the Great ");
  strcpy(q[26],
         " \"Es gibt zwei menschliche Hauptsünden, aus welchen sich alle "
         "andern ableiten: Ungeduld und Lassigkeit.\" \"There Are Two Main "
         "Human Sins from Which All the Others Derive: Impatience and "
         "Indolence.\" — Franz Kafka, Die Zürauer Aphorismen  ");
  strcpy(q[27],
         " \"Homo homini lupus\" \"Man is wolf to man\" — Plautus, Asinaria ");
  strcpy(
      q[28],
      " \"It Is Better to Receive an Injury than to Inflict One.\"\"Accipere "
      "quam facere injuriam praestat.\" — Cicero, Tusculanae Disputationes ");
  strcpy(q[29], " \"Change Your Desires Rather than the Order of the World.\" "
                "\"À changer mes désirs que l'ordre du monde.\" — René "
                "Descartes, Discours de la Méthode ");
  strcpy(q[30], " সবাই সবকিছু ডিজার্ভ করে না, সবাই সবকিছুর যোগ্য না - Ibnul Abrar "
                "Shahriar Seam, KU CSE`23 ");
  // ======================================================================================
  time_t now = time(NULL);
  struct tm *local = localtime(&now);
  int today = local->tm_mday - 1;
  printf("today is = %d\n\n", today + 1);
  printf("%s", q[today]);
}
