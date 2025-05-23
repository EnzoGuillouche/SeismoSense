# Functional Specifications - SeismoSense

<details>

<summary>Click to expand</summary>

- [Functional Specifications - SeismoSense](#functional-specifications---seismosense)
  - [Project Overview](#project-overview)
    - [Project Goals](#project-goals)
    - [Resources and Constraints](#resources-and-constraints)
      - [Resources](#resources)
      - [Constraints](#constraints)
    - [Stakeholders](#stakeholders)
    - [Target Audience](#target-audience)
  - [Personas and Use Cases](#personas-and-use-cases)
  - [Functional Requirements](#functional-requirements)
    - [Simulation](#simulation)
      - [Simulation Interface](#simulation-interface)
      - [Simulation Configuration](#simulation-configuration)
      - [Simulation Visualization](#simulation-visualization)
    - [Structural Analysis](#structural-analysis)
    - [Performance Metrics](#performance-metrics)
      - [JSON reports](#json-reports)
  - [Non-functional Requirements](#non-functional-requirements)

</details>

## Project Overview

This project deals with developing a cutting-edge earthquake simulation tool designed to test the structural resilience of buildings and other infrastructure under various seismic scenarios.

### Project Goals

I would want to perform few goals with this project:

- Simulate earthquakes effectively and in a semi-realistic way.
- Create a user-friendly interface to set easily earthquakes' parameters.
- Export detailed analysis reports of the simulated disasters.
- Demonstrate visually how infrastructures react when exposed to earthquakes.

### Resources and Constraints

#### Resources

- **GitHub**: Inspiring from other projects (related to this one or not) could be useful to perform the project.
- **Online resources**: Specific physics and dynamics are needed to be learned to perform the project. Also, open-source libraires will be useful.

#### Constraints

- **Simulation creation**: A strict simulation of a natural disaster is quite tough to create.
- **Development Time**: The project has to be performed in the mean time of my studies at ALGOSUP, meaning that I need to manage my time efficiently to complete all deliverables on schedule.

### Stakeholders

| Role            | Representative | Expectations                                                           |
| --------------- | -------------- | ---------------------------------------------------------------------- |
| School director | Franck JEANNIN | Clear documentation, management and dedication based on the skills learnt in class |

### Target Audience

The target audience includes:

- Researchers
- Urban engineers
- Students

To ensure the project meets all the needs of the target audience, it must strike a balance between **detail** and **understandability**.

---

## Personas and Use Cases

---

## Functional Requirements

This earthquake simulation tool must provide a real-time, immersive, and scientifically accurate environment to test and analyze the behavior of buildings and infrastructures during seismic events. The simulation will serve as a diagnostic and research-grade tool for the users.
The functional requirements are organized into three main areas: **Simulation**, **Structural Analysis**, and **Performance Metrics**.

### Simulation

The core of the system lies in its ability to create realistic and interactive earthquake simulations.

#### Simulation Interface

- User-Friendly Interface
  - An intuitive graphical user interface that allows users to:
    - Select predefined building templates.
    - View real-time simulation output via 3D visualizations.
    - Pause, resume, rewind, and replay simulations.

#### Simulation Configuration

The simulation allows users to configure simulation parameters, listed below with their category and how they change the simulation output:

| **Category**  | **Parameter**             | **What It Relates To**         |
| ------------- | ------------------------- | ------------------------------ |
| Seismic Event | Magnitude                 | Intensity of ground motion     |
|               | Epicenter & Depth         | Distance/damage potential      |
|               | Duration                  | Fatigue and total impact       |
|               | Wave Types & Frequencies  | Type of structural motion      |
|               | Ground Acceleration (PGA) | Force on structure             |
| Geotechnical  | Soil Type                 | Wave amplification/dampening   |
|               | Liquefaction              | Ground failure potential       |
|               | Topography                | Local seismic effects          |
|               | Soil Damping              | Energy dissipation             |
| Structural    | Mass Distribution         | Inertial response              |
|               | Material Properties       | Strength and flexibility       |
|               | Natural Frequency         | Resonance risk                 |
|               | Damping Ratio             | Oscillation control            |
|               | Foundation Type           | Interaction with soil          |
|               | Irregularities            | Unexpected structural behavior |
| Contextual    | Occupancy Type            | Safety thresholds              |
|               | Nearby Structures         | Systemic risk                  |

#### Simulation Visualization

- Real-Time Structural Response Visualization
  - Animate infrastructure deformations such as:
    - Structural displacement and oscillation.
    - Cracks, buckling, or fractures in real-time (if possible).
- Progressive failure visualization (e.g., beam collapse or wall cracking).
  - Soil-Structure Interaction (SSI)
  - Allow the simulation of different soil compositions (e.g., clay, sand, rock).
  - Model how soil dampening and resonance influence building response.
  - Visualize how foundation and substructure interact with terrain.

All the visuals are designed here: https://excalidraw.com/#json=riZxaUI3C_18cf9dc-94s,WoXwZhLVpFS1wYrAZffypQ

### Structural Analysis

To ensure the tool is not merely visual but also analytically powerful, it must offer core engineering insights.
It is basically the system which does the calculations, its outputs are useful to both the visual simulation and the performance metrics.

- Structural Component Behavior Tracking
  - Differentiate between materials (steel, concrete, wood) with varying elasticity, ductility, and failure thresholds.
  - Monitor deformation of key components:
    - beams
    - columns
    - walls
    - joints
  - Detect and log overstressed or failed regions.
- Resonance and Damping Effects
  - Account for natural frequency of structures and evaluate resonance amplification.
  - Allow configuration of damping factors (passive or active dampers).

### Performance Metrics

Quantitative analysis is vital for evaluating the impact of simulated seismic events.

- Live Metric Dashboards
  - Display values such as:
    - Peak Ground Acceleration (PGA)
    - Maximum Interstory Drift Ratio
    - Stress/Strain over time
    - Total energy absorbed or dissipated
- Safety and Compliance Evaluation
  - Estimate damage levels and categorize them (Minor, Moderate, Severe, Collapse).
  - Check for compliance with structural safety codes (optionally based on region-specific norms, like Eurocode or ASCE).
- Report Generation and Export
  - Generate detailed simulation reports including:
    - Structural performance summary.
    - Time-series graphs and visual data overlays.
    - Breakdown of failure points and likely causes.
  - Export reports in JSON format (useful for integration into external tools).

#### JSON reports

The JSON reports have a specific structure that make them readable and understandable, as well as precise and reliable.
Its naming conventions are `full-name-id.json`.

**simulationInfo** is the part containing the overall simulation information:

- "simulationId" contains the simulation ID (the same as in the file name).
- "status" stands for ensuring the simulation failed or not. Typically "Completed" or "Failed".
- "duration" is a floating number relating to the whole simulation duration. The unit is in seconds (s).

**seismicEvent** is the part containing the earthquake's parameters:

- "magnitude" is a floating number relating to the earthquake's magnitude.
- "epicenter" is an object containing the "x_coordinates" and "y_coordinates" of the earthquake's epicenter. Each coordinate is a floating number.
- "depth" is a floating number relating to the earthquake's depth (being the z-coordinates of the epicenter).
- "duration" is a floating number relating to the earthquake duration. The unit is in seconds (s).
- "groundAcceleration" is the part that quantifies how strongly the ground shakes during the earthquake:
  - "PGA" is a floating number representing the Peak Ground Acceleration. This value relates to the force that structures experience. The unit is g (gravitational acceleration).
  - "PGV" is a floating number representing the Peak Ground Velocity. It reflects the maximum speed at which the ground moves during the quake. The unit is in centimeters per second (cm/s).
- "waveCharacteristics" defines the nature of seismic waves generated during the event, which affect how structures vibrate:
  - "types" is an array of strings listing the types of seismic waves involved in the simulation:
    - "P-wave" (primary wave): Fastest wave, compresses and expands ground in the direction of travel.
    - "S-wave" (secondary wave): Slower but more destructive, moves ground perpendicular to travel direction.
    - "Surface wave": Travels along the Earth’s surface, typically causes the most damage due to large amplitude and long duration.
  - "dominantFrequencies" is an array of floating numbers representing the main frequencies of the seismic waves. These frequencies determine how likely a structure is to resonate with the quake. The unit is in Hertz (Hz).
  - "resonantFrequency" is a floating number indicating the frequency at which the simulated building or structure naturally resonates. The unit is in Hertz (Hz).

**siteConditions** defines the geological and environmental context of the simulated area, which significantly affects how seismic waves interact with the structure:

- "soilType" describes the dominant soil in the area (e.g., "Soft clay", "Dense sand", "Rock"). This impacts how seismic waves are amplified or attenuated.
- "liquefactionRisk" indicates the likelihood of soil liquefaction during shaking. Typically "Low", "Moderate", or "High".
- "soilDampingRatio" is a floating number (between 0 and 1) expressing the inherent energy dissipation capability of the soil. A higher ratio means the ground can absorb more seismic energy, reducing structural vibration.
- "topography" describes the terrain shape at the simulation site (e.g., "Flat", "Slope", "Valley"). Topographic features can focus or scatter seismic energy, changing the intensity and direction of shaking.

**structure** contains all the technical and contextual information about the building or infrastructure being tested:

- "buildingId" is a unique ID for the simulated structure.
- "buildingType" defines the structural system of the building, such as "Reinforced Concrete Frame", "Steel Moment Frame", "Masonry" etc.
- "materialProperties" is an array of objects that define the physical characteristics of the materials used in the building’s construction. Each object represents a material type and includes relevant engineering parameters that determine how it responds under seismic stress:
  - "materialType" indicates the class or kind of material used, e.g., "High-Strength Composite", "Engineered Timber", or "Low-Strength Masonry". This abstracts away from traditional material labels and focuses on performance characteristics.
  - "elasticModulus" is a floating number (in GPa) that defines the material’s stiffness—how much it resists elastic (temporary) deformation under stress.
  - "yieldStrength" is a floating number (in MPa) showing the stress at which the material transitions from elastic to plastic behavior—this is when permanent deformation begins.
  - "ultimateStrain" is a floating number indicating how much strain (deformation relative to original size) the material can undergo before complete failure. This tells us about brittleness or ductility.
  - "ductilityRatio" is a unitless value that defines the capacity to undergo plastic deformation without breaking. Higher values are desirable for seismic performance because ductile materials absorb more energy.
  - "energyAbsorptionCapacity" summarizes the material’s ability to absorb and dissipate seismic energy before failure. Typically "Low", "Moderate" or "High".
  - "resilience" qualitatively describes how well the material recovers from deformation or stress, useful for post-earthquake structural assessments. Typically "Poor", "Moderate" or "Excellent".
- "massDistribution" describes how the mass is spread throughout the structure (e.g., "Uniform", "Top-Heavy"). Uneven distribution can cause torsional response and stress concentration.
- "naturalFrequency" is a floating number representing the natural vibration frequency of the structure. If this value is close to the dominant seismic wave frequency, resonance can amplify shaking. The unit is in Hertz (Hz).
- "dampingRatio" is a floating number (between 0 and 1) defining the damping capacity of the structure itself. It reflects how quickly oscillations die out after shaking.
- "foundationType" indicates how the structure is anchored to the ground (e.g., "Shallow", "Deep pile", "Mat foundation"). The foundation affects how seismic forces are transferred to the building.
- "occupancyType" defines the function of the structure (e.g., "Hospital", "School", "Residential"). Useful for safety and regulatory considerations and may influence acceptable performance thresholds.
- "nearbyStructures" is an array of objects that represent other buildings in proximity:
Each object contains:
  - "buildingId": An ID of the nearby structure.
  - "distance": A floating number specifying the distance in meters from the main structure. Close distances may lead to pounding effects or collective risk in urban areas.

**structuralResponse** is the section that captures how the building or structure behaved during the simulated earthquake. It includes both overall metrics and per-component breakdowns of damage and stress:

- "maxDisplacement" is a floating number representing the maximum horizontal or vertical movement experienced by the structure during the event. The unit is in centimeters (cm).
- "maxInterstoryDriftRatio" is an unitless floating number expressing the maximum relative displacement between two consecutive floors, divided by the floor height.
- "components" is an object detailing the performance and damage state of individual structural elements:
  - "beams" tracks key horizontal support members.
    - "failed" is the number of beams that have fully fractured or collapsed during the simulation.
    - "overstressed" is the number of beams that exceeded safe stress thresholds but have not completely failed.
  - "columns" tracks vertical load-bearing members.
    - "failed" counts columns that lost their load-bearing capacity, often resulting in partial or total collapse.
    - "overstressed" counts columns that were pushed beyond design limits but did not fail completely.
  - "walls" includes both load-bearing and partition walls.
    - "cracked" refers to walls that developed visible structural or surface cracks due to tensile stress.
    - "buckled" indicates walls that deformed or bowed due to compressive forces, suggesting near-failure or collapse.
  - "joints" monitors the connections between structural elements (beam-column joints, wall-slab joints, etc.).
    - "damaged" refers to joints that have experienced partial failure, loosening, or cracking, affecting the overall structural integrity.
- "resonanceDetected" is a boolean value that indicates whether the building's natural frequency aligned with the dominant frequency of the seismic waves, which would result in amplified motion and elevated structural risk.
- "dampingEffectiveness" qualitatively indicates how well the building’s damping systems or natural damping characteristics reduced oscillations and energy transfer during the earthquake. Typically "Low", "Moderate" or "High".

**performanceMetrics** summarizes the quantitative results of the simulation and evaluates the structure’s behavior under seismic stress in terms of energy, safety, and code compliance:

- "totalEnergyInput" is a floating number representing the total seismic energy transferred from the ground to the structure. This includes the energy carried by all types of seismic waves over the simulation duration. The unit is in kilojoules (kJ).
- "totalEnergyDissipated" is a floating number indicating how much of that energy was absorbed or dampened by the structure through mechanisms such as friction, plastic deformation, or engineered dampers. The difference between input and dissipated energy can reflect how much energy remained in the form of structural vibration or damage. The unit is in kilojoules (kJ).
- "safetyEvaluation" is an object that gives a summarized safety status of the structure post-earthquake:
  - "damageLevel" qualitatively describes the overall damage state based on combined component performance and drift metrics. It helps in risk classification and repair prioritization. Typically "Minor", "Moderate", "Severe" or "Collapse".

[Here](./example-report-EXME2025.json) is an example of the JSON reports exported from the simulation.

---

## Non-functional Requirements

---
