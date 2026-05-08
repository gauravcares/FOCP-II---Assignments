#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

// Replace all occurrences of {name} in a template with the actual name
std::string fillTemplate(const std::string& tmpl, const std::string& name) {
    std::string result = tmpl;
    const std::string placeholder = "{name}";
    size_t pos = 0;
    while ((pos = result.find(placeholder, pos)) != std::string::npos) {
        result.replace(pos, placeholder.length(), name);
        pos += name.length();
    }
    return result;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> roastTemplates = {
        "Hey {name}, I'd roast you, but my mom said I'm not allowed to burn trash.",
        "{name}? More like {name}-ger for attention. Is it working?",
        "They say every person has a gift. Yours must still be in the mail, {name}.",
        "{name}, you're proof that even evolution takes breaks.",
        "I'd agree with you, {name}, but then we'd both be wrong.",
        "Scientists say the universe is made of protons, neutrons, and electrons. They forgot to mention morons like {name}.",
        "{name}, you're not stupid — you just have bad luck thinking.",
        "If brains were chocolate, {name} wouldn't have enough to fill an M&M.",
        "{name}, you're the reason they put instructions on shampoo bottles.",
        "I've seen better decisions made in horror movies than the ones you make, {name}.",
        "{name}, your WiFi password is probably '1234' and you're proud of it.",
        "Calling you average would be a compliment, {name}. Average is at least on the chart.",
        "{name}, you're not the dumbest person alive — but you better hope they don't die.",
        "The only thing sharp about you, {name}, is your elbows.",
        "{name}, I was going to give you a nasty look, but I see you already have one.",
        "I'd insult your intelligence, {name}, but that would require you to have some.",
        "{name}, you're like a software update — nobody asked for you, but here we are.",
        "I'd call you a clown, {name}, but that would be an insult to clowns.",
        "{name}, if ignorance is bliss, you must be the happiest person alive.",
        "They say laughter is the best medicine. One look at you, {name}, and the whole room is cured.",
        "{name}, you're living proof that even AI can't fix bad decisions.",
        "I thought of you today, {name}. It reminded me to clean my room.",
        "{name}, your search history is probably just 'how to be interesting'.",
        "People say honesty is a virtue, {name}. Honestly? You test that theory daily.",
        "{name}, you're the human equivalent of a participation trophy.",
    };

    std::string userName;
    std::cout << "========================================\n";
    std::cout << "         Welcome to Roast-O-Matic!\n";
    std::cout << "========================================\n";
    std::cout << "Enter your name (if you dare): ";
    std::getline(std::cin, userName);

    // Trim leading/trailing whitespace
    size_t start = userName.find_first_not_of(" \t\r\n");
    size_t end   = userName.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) {
        userName = "Coward";
    } else {
        userName = userName.substr(start, end - start + 1);
    }

    int index = std::rand() % static_cast<int>(roastTemplates.size());
    std::string roast = fillTemplate(roastTemplates[index], userName);

    std::cout << "\n*** ROAST OF THE DAY ***\n";
    std::cout << "----------------------------------------\n";
    std::cout << roast << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << "(Don't take it personally, " << userName << ". We roast the ones we... tolerate.)\n\n";

    return 0;
}
