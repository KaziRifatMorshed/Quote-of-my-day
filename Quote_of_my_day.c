/*
# Program Name: Quote of my day
# Author: Kazi Rifat Morshed (KU CSE 230220, 230220@ku.ac.bd)
# Special thanks to @cococry
# DATE: July-August 2024
# Platform: GNU/Linux (tested on arch base distro)
# Program Description: This is a GUI desktop app for personal use which will
remind me a quote every day from its internally set 31 quotes.

# LIBRARY INSTALLATION (for arch linux):
    ```
    sudo pacman -S glfw
    git clone https://github.com/cococry/leif.git && cd leif/ && ./install.sh
    paru -S libclipboard-git
    ```

# COMPILATION COMMAND WITH PARAMETERS:
    `clang Quote_of_my_day.c -o Quote_of_my_day -lglfw -lGL -lleif -lclipboard
-lm && ./Quote_of_my_day`

*/

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cglm/types-struct.h>
#include <leif/leif.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

char q[31][470] = {0};
#define WIN_MARGIN 20.0f
static int win_w = 1280, win_h = 720;
static LfFont my_font_head, my_font_body;

// ===========================================================================
// ------------------------------- FUNCTIONS ---------------------------------
// ===========================================================================

uint32_t get_today_date() { // this function returns the date in integer
  time_t now = time(NULL);
  struct tm *local = localtime(&now);
  return (local->tm_mday);
}

char *get_quote(uint32_t n) {
  return &q[(n - 1)][0];
} // returning pointer considering index numbering starting from zero

static void render_top_bar() {
  lf_push_font(&my_font_head), lf_text("Quote of my day..."), lf_pop_font();
  // exit button
  const float width = 160.0f;

  LfUIElementProps props = lf_get_theme().button_props;
  lf_set_ptr_x_absolute(win_w - width - WIN_MARGIN * 2.0f);
  props.margin_left = 0.0f, props.margin_right = 0.0f, props.margin_top = 0.0f;
  props.color = (LfColor){65, 167, 204, 255};
  props.border_width = 0.0f, props.corner_radius = 4.0f;
  lf_push_style_props(props);
  lf_set_line_should_overflow(false);
  lf_button_fixed(":q!", width, -1); // how minus 1 ?
  lf_set_line_should_overflow(true); // to avoid overriding
  lf_pop_style_props();
}

static void render_Quote(uint32_t n) { // GUI
  lf_set_ptr_y_absolute(150.0f);
  lf_push_font(&my_font_body), lf_text(get_quote(n)), lf_pop_font();
}

static void print_to_console(uint32_t n) {
  printf("Quote of day %d and quote is : \n%s", n, get_quote(n));
  return;
}

static void cli_print_help() {
  printf("\nGuide of \"Quote of my day\" for/by Kazi Rifat Morshed\n"
         "use \'-h\' or \"--help\" to learn  how to use it.\n\n"
         "No Parameter(just ./\" Quote_of_my_day \") will both print in "
         "console and launch GUI showing quote of this date (today).\n"
         "\'-c\' or \"--cli\"\t:\tPrints in console of this date (today)\n"
         "\'-g\' or \"--gui\"\t:\tOpens GUI window showing quote of this date "
         "(today)\n\n"
         "To get quote of any specific date:\n"
         "add the date (digit) after any of \'-c\' or \"--cli\" or \'-g\' or "
         "\"--gui\" parameters\n\nNOTE: this program was made for personal "
         "use only");
}

static void launch_gui(uint32_t n) {
  glfwInit();
  GLFWwindow *_window =
      glfwCreateWindow(win_w, win_h, "Quote of My Day...", NULL, NULL);

  glfwMakeContextCurrent(_window);
  lf_init_glfw(win_w, win_h, _window);

  LfTheme _theme = lf_get_theme();
  _theme.div_props.color = LF_NO_COLOR, lf_set_theme(_theme);
  my_font_head = lf_load_font("./font/CalibriLight.ttf", 50);
  my_font_body = lf_load_font("./font/CalibriLight.ttf", 45);

  while (!glfwWindowShouldClose(_window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    lf_begin();
    lf_div_begin(
        ((vec2s){WIN_MARGIN, WIN_MARGIN}),
        ((vec2s){win_w - WIN_MARGIN * 2.0f, win_h - WIN_MARGIN * 2.0f}),
        (true));
    // --------------------------------------------------
    render_top_bar();
    lf_next_line();
    lf_set_line_should_overflow(true);
    render_Quote(n);
    lf_set_line_should_overflow(false);
    lf_next_line();

    lf_div_end();
    lf_end();

    glfwPollEvents();
    glfwSwapBuffers(_window);
  }

  lf_free_font(&my_font_head), lf_free_font(&my_font_body);
  glfwDestroyWindow(_window);
  glfwTerminate();
}

// --------------------------- DATABASE OF QUOTES ----------------------------
static void load_all_quotes() {
  strcpy(q[0], " \"To live is to think.\" - Marcus Tullius Cicero ");
  strcpy(
      q[1],
      " \"Power tends to corrupt and absolute power corrupts "
      "absolutely.\nGreat "
      "men are almost always bad men, even \nwhen they exercise influence and "
      "not authority;\nstill more when you superadd the tendency of the \n"
      "certainty of corruption by authority.\" \n\t- Lord Anton ");
  strcpy(q[2],
         " \"The difference between the novice and the master is \nthat the "
         "master has failed more times than the novice has tried.\" \n"
         "-Korosensei (Anime: Assassination Classroom; Author: Yusei Matsui) ");
  strcpy(q[3],
         " \"It's human nature not to realize the true value of \n"
         "something unless they lose it.\" - Orochimaru (Anime: Naruto) ");
  strcpy(q[4],
         " \"Wake up to reality! Nothing ever goes as planned in this \n"
         "world. The longer you live, the more you realize that in this \n"
         "reality only pain, suffering and futility exist.\" \n- Madara "
         "Uchiha (Anime: Naruto; Author: Masashi Kishimoto) ");
  strcpy(q[5], " \"Neque porro quisquam est qui dolorem ipsum quia dolor sit \n"
               "amet, consectetur, adipisci velit...\" <!--\"There is no one \n"
               "who loves pain itself, who seeks after it and wants to have \n"
               "it, simply because it is pain...\"--> ");
  strcpy(
      q[6],
      " \"Jibone ki hoite cai? Manush Hoite cai. Beshi Upor e Uthte cai na \n"
      "jate nicer manushguloke tuccho piprar moto dekhay. Beshi niche \nnamte "
      "cai na"
      "jate sobai amake pipra vebe mariye fele. \nKhub iccha ache,\n"
      "Ekdin nijeke Manush bole dabi korbo.\" \n\t- Raihan Rahee (NSTU) \n");
  /*
\"জীবনে কি হইতে চাই? মানুষ হইতে চাই। বেশি উপরে উঠতে চাইনা, \n"
               "যাতে নিচের মানুষগুলোকে তুচ্ছ পিঁপড়ার মত দেখায়। বেশি নিচে নামতে \n"
               "চাইনা যাতে সবাই আমাকে পিঁপড়া ভেবে মাড়িয়ে দেয়। খুব ইচ্ছা আছে, \n"
               "একদিন নিজেকে মানুষ দাবী করবো।\" - রায়হান রাহী (NSTU) \n
*/
  strcpy(
      q[7],
      " \"An idiot admires complexity, a genius admires simplicity, \na"
      "physicist tries to make it simple, for an idiot anything the more \n"
      "complicated it is the more he will admire it if you make something \n"
      "so clusterfucked he can't understand it he's gonna think you're a \n"
      "god cause you made it so complicated nobody can understand it. \n"
      "That's how they write journals in Academics, they try to make it so \n"
      "complicated people think you're a genius\"\n\t- Terry Davis \0"); // issue
  // not stopping
  strcpy(q[8], " \"Anything can be a sword if you polish it enough.\" "
               "\n-Shiota Nagisa \n"
               "(Anime: Assassination Classroom; Author: Yusei Matsui) ");
  strcpy(
      q[9],
      " \"As you go through life, the might current of society is bound to \n"
      "get in your way and there will certainly be times when things don't \n"
      "go as you'd hoped.\" \n-Koro-sensei \n(Anime: Assassination "
      "Classroom) ");
  strcpy(q[10], " \"The world will always be filled with injustice.\" \n"
                "-Koro-sensei (Anime: Assassination Classroom) ");
  strcpy(q[11],
         " \"When the student is ready, \nthe teacher will appear. \nWhen the "
         "student is truly ready, \nthe teacher will disappear.\" \n- "
         "well-known proverb ");
  strcpy(q[12],
         " \"We Act According To Our Own Sense Of Justice.\"; \n\"If You Don't "
         "Share Someone's Pain, \nYou Can Never Understand Them.\" ");
  strcpy(
      q[13],
      " Don't just learn, experience. Don't just read, absorb. Don't just \n"
      "change, transform. Don't just relate, advocate. Don't just promise, \n"
      "prove. Don't just criticize, encourage. Don't just think, ponder. Don't "
      "\n"
      "just take, give. Don't just see, feel. Don't just dream, do. Don't just "
      "\n"
      "hear, listen. Don't just talk, act. Don't just tell, show. Don't just \n"
      "exist, live.\" \n- Roy T. Bennett, The Light in the Heart ");
  strcpy(q[14],
         " \"Success is not how high you have climbed, but how you make \n"
         "a positive difference to the world.\" \n- Roy T. Bennett, The "
         "Light in the Heart ");
  strcpy(q[15],
         " \"If you know the enemy and know yourself, you need not fear \n"
         "the result of a hundred battles. If you know yourself but not "
         "the enemy, \nfor every victory gained you will also suffer a "
         "defeat. \nIf you know neither the enemy nor yourself, \nyou will "
         "succumb in every battle.\"\n\t- Sun Tzu, The Art of War ");
  strcpy(q[16], " \"In the midst of chaos, there is also opportunity\" \n\t- "
                "Sun-Tzu, A Arte da Guerra ");
  strcpy(q[17],
         " \"To know your Enemy, you must become your Enemy.\" \n\t- Sun Tzu ");
  strcpy(q[18], " \"Appear weak when you are strong, \nand strong when you are "
                "weak.\" \n\t- Sun Tzu, The Art of War ");
  strcpy(q[19], " Make yourself necessary and you will always be needed. \nIf "
                "you want to feel successful, \nlearn to create, innovate, or "
                "design something \nother people can use and need. ");
  strcpy(
      q[20],
      " You never really lose until you stop trying. \nThe words \"I can't\" "
      "never accomplish anything. \n\"I'll try,\" on the other hand, can "
      "perform wonders. \nUntil you try you don't know what you can do. ");
  strcpy(q[21],
         " Rule your mind or it will rule you. \nWhen you rule your mind "
         "by controlling \nnegativity and doubt, you rule your world. \nThe "
         "choice is yours to make every day. ");
  strcpy(
      q[22],
      " All men can see these tactics whereby I conquer, \nbut what none can "
      "see is the strategy out of which \nvictory is evolved. \n\t- Sun Tzu ");
  strcpy(q[23],
         " The less men think, the more they talk. - Montesquieu; \nA "
         "woman simply is, but a man must become. - Camille Paglia ; \n\n"
         "\"A Man Who Cannot Command Himself Will Always Be a Slave.\" \n"
         "\"Wer sich nicht selbst befiehlt, bleibt immer Knecht.\" \n— "
         "Johann Wolfgang von Goethe, Zahme Xenien ");
  strcpy(q[24], " Give me six hours to chop down a tree \nand I will spend the "
                "first four \nsharpening the axe. \n\t- Abraham Lincoln ");
  strcpy(
      q[25],
      " I am not afraid of an army of lions \nled by a sheep; I am afraid of \n"
      "an army of sheep led by a lion. \n\t- Alexander the Great ");
  strcpy(q[26],
         " \"Es gibt zwei menschliche Hauptsünden, aus welchen sich alle \n"
         "andern ableiten: Ungeduld und Lassigkeit.\" \n\n\"There Are Two Main "
         "Human Sins \nfrom Which All the Others Derive: \nImpatience and "
         "Indolence.\" \n\t- Franz Kafka, Die Zürauer Aphorismen  ");
  strcpy(q[27], " \"Homo homini lupus\" \n\"Man is wolf to man\" \n\t- "
                "Plautus, Asinaria ");
  strcpy(
      q[28],
      " \"It Is Better to Receive an Injury than to Inflict One.\"\n\"Accipere "
      "quam facere injuriam praestat.\" \n\t- Cicero, Tusculanae "
      "Disputationes ");
  strcpy(q[29],
         " \"Change Your Desires Rather than the Order of the World.\" \n"
         "\"À changer mes désirs que l'ordre du monde.\" \n- René "
         "Descartes, Discours de la Méthode ");
  strcpy(q[30], " \"...Sobai Sobkichu Deserve kore na, Sobai sobkisur joggo "
                "na...\" \n- Ibnul Abrar Shahriar Seam, KU CSE`23 ");
}
/* ------------- ARCHIEVE ----------
static void load_all_quotes() {
  strcpy(q[0], " \"To live is to think.\" - Marcus Tullius Cicero ");
  strcpy(
      q[1],
      " \"Power tends to corrupt and absolute power corrupts absolutely. Great "
      "men are almost always bad men, even when they exercise influence and "
      "not authority; still more when you superadd the tendency of the "
      "certainty of corruption by authority.\" - Lord Anton ");
  strcpy(q[2],
         " \"The difference between the novice and the master is that the "
         "master has failed more times than the novice has tried.\" "
         "-Korosensei (Anime: Assassination Classroom; Author: Yusei Matsui) ");
  strcpy(q[3], " \"It's human nature not to realize the true value of "
               "something unless they lose it.\" - Orochimaru (Anime: Naruto)
"); strcpy(q[4], " \"Wake up to reality! Nothing ever goes as planned in this "
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
         "complicated people think you're a genius\" - Terry Davis ");
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
      "exist, live.\" - Roy T. Bennett, The Light in the Heart ");
  strcpy(q[14], " \"Success is not how high you have climbed, but how you make "
                "a positive difference to the world.\" - Roy T. Bennett, The "
                "Light in the Heart ");
  strcpy(q[15], " \"If you know the enemy and know yourself, you need not fear "
                "the result of a hundred battles. If you know yourself but not "
                "the enemy, for every victory gained you will also suffer a "
                "defeat. If you know neither the enemy nor yourself, you will "
                "succumb in every battle.\"\t- Sun Tzu, The Art of War ");
  strcpy(q[16], " \"In the midst of chaos, there is also opportunity\" - "
                "Sun-Tzu, A Arte da Guerra ");
  strcpy(q[17],
         " \"To know your Enemy, you must become your Enemy.\" \t- Sun Tzu ");
  strcpy(q[18], " \"Appear weak when you are strong, and strong when you are "
                "weak.\" \t- Sun Tzu, The Art of War ");
  strcpy(q[19], " Make yourself necessary and you will always be needed. If "
                "you want to feel successful, learn to create, innovate, or "
                "design something other people can use and need. ");
  strcpy(q[20],
         " You never really lose until you stop trying. The words \"I can't\" "
         "never accomplish anything. \"I'll try,\" on the other hand, can "
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
  strcpy(q[30], " \"...Sobai Sobkichu Deserve kore na, Sobai sobkisur joggo "
                "na...\" - Ibnul Abrar "
                "Shahriar Seam, KU CSE`23 ");
}
*/

// ===========================================================================
// --------------------------- MAIN FUNCTION ---------------------------------
// ===========================================================================

/*
-c --cli : CLI OUTPUT only, won't run GUI APP
default : opens a GUI window as well as shows quote in CLI
*/

int main(int argc, char *argv[]) {
  load_all_quotes();

  if (argc == 1) { // no parameter, both cli & GUI for today
    print_to_console(get_today_date());
    printf("");
    launch_gui(get_today_date());
    return 0;
  } else if (argc == 2) {
    if ((strcasecmp(argv[1], "-h") == 0 ||
         strcasecmp(argv[1], "--help") == 0)) {
      cli_print_help();
      return 0;
    }
    if ((strcasecmp(argv[1], "-c") == 0 || strcasecmp(argv[1], "--cli") == 0)) {
      print_to_console(get_today_date());
      return 0;
    } else if ((strcasecmp(argv[1], "-g") == 0 ||
                strcasecmp(argv[1], "--gui") == 0)) {
      launch_gui(get_today_date());
      return 0;
    }
  } else if (argc == 3) {
    uint32_t n = (uint32_t)atoi(argv[2]);
    if ((n < 1) || (n > 31)) {
      n = 1;
    }
    if ((strcasecmp(argv[1], "-c") == 0 || strcasecmp(argv[1], "--cli") == 0)) {
      print_to_console(n);
      return 0;
    } else if ((strcasecmp(argv[1], "-g") == 0 ||
                strcasecmp(argv[1], "--gui") == 0)) {
      launch_gui(n);
      return 0;
    }
  } else {
    printf("\nINACURATE ARGUMENT PASSING ERROR !!! Learn UNIX CLI bro !\n"
           "use \'-h\' or \"--help\" to learn  how to use it.\n\n");
  }

  // the end
  return 0;
}