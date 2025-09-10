# Arduino Project Template

Use this template when creating new Arduino projects for the Arduino Journey repository.

## Project Structure
```
XX-project-name/
├── README.md              # Project documentation
├── project_name.ino       # Main Arduino sketch
├── circuit.fzz           # Fritzing circuit file (optional)
├── images/               # Circuit diagrams, photos
│   ├── circuit-diagram.png
│   └── breadboard-layout.jpg
└── extras/               # Additional files
    ├── libraries/        # Custom libraries if needed
    └── variations/       # Alternative code versions
```

## README Template
Copy and modify this structure for your project README:

```markdown
# Project XX: [Project Name] [Emoji]

## Overview
Brief description of what this project does and what it demonstrates.

## What You'll Learn
- Concept 1
- Concept 2
- Concept 3

## Components Required
- Arduino Uno/Nano
- Component 1
- Component 2
- Resistors, wires, breadboard

## Circuit Diagram
[Include ASCII art or reference to image file]

## Code Explanation
### Key concepts with code snippets

## Upload Instructions
1. Step by step instructions

## Expected Behavior
What should happen when the code runs

## Troubleshooting
Common issues and solutions

## Variations to Try
Ideas for extending the project

## Next Steps
What to learn next
```

## Code Template
Use this structure for Arduino sketches:

```cpp
/*
  [Project Name] - Arduino Journey Project XX
  
  [Brief description of what the project does]
  
  Circuit:
  - [Component connections]
  
  Created: [Year]
  By: Arduino Journey
*/

// Pin definitions
const int PIN_NAME = 2;  // Description

// Global variables
int variableName = 0;

void setup() {
  // Pin configurations
  pinMode(PIN_NAME, OUTPUT);
  
  // Serial communication
  Serial.begin(9600);
  Serial.println("[Project Name] Started!");
}

void loop() {
  // Main program logic
}

// Custom functions
void customFunction() {
  // Function implementation
}
```

## Documentation Guidelines

### Circuit Diagrams
- Include both schematic and breadboard layouts
- Use consistent component symbols
- Label all connections clearly
- Show component values (resistor values, etc.)

### Code Comments
- Explain WHY not just WHAT
- Comment complex algorithms
- Include pin definitions at the top
- Use consistent naming conventions

### Troubleshooting Section
Always include common issues:
- Connection problems
- Upload errors
- Unexpected behavior
- Component orientation issues

### Learning Progression
- Build on previous projects
- Introduce one new concept at a time
- Provide variations for different skill levels
- Suggest next logical steps

## Naming Conventions

### Project Folders
- Use format: `XX-descriptive-name`
- XX = zero-padded project number (01, 02, etc.)
- Use hyphens, not spaces or underscores
- Keep names concise but descriptive

### File Names
- Arduino sketch: `descriptive_name.ino` (underscores)
- README: `README.md` (exactly this name)
- Images: `descriptive-name.png/jpg` (hyphens)

### Code Variables
- Use camelCase for variables: `buttonState`
- Use UPPER_CASE for constants: `LED_PIN`
- Be descriptive: `temperatureSensor` not `temp`

## Image Guidelines

### Circuit Diagrams
- PNG format for diagrams
- JPEG for photos
- Minimum 800px width
- Clear, high contrast
- Include in `images/` folder

### Documentation Images
- Show actual breadboard layout
- Include component labels
- Good lighting for photos
- Multiple angles if helpful

## Testing Checklist

Before publishing a project:
- [ ] Code compiles without errors
- [ ] Circuit diagram matches actual connections
- [ ] All components listed in requirements
- [ ] README follows template structure
- [ ] Troubleshooting section included
- [ ] Code is commented appropriately
- [ ] Variations or extensions suggested
- [ ] Links to previous/next projects work

## Project Ideas by Difficulty

### Beginner (Digital I/O)
- LED patterns
- Button controls
- Buzzers and sounds
- Simple sensors

### Intermediate (Analog, PWM)
- Sensor readings
- Motor control
- PWM effects
- Data logging

### Advanced (Communication, Complex Logic)
- WiFi connectivity
- Multiple sensor integration
- Real-time systems
- Custom protocols

Remember: Each project should build upon previous knowledge while introducing new concepts gradually!