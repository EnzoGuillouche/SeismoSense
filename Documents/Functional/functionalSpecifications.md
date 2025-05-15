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

### Structural Analysis

To ensure the tool is not merely visual but also analytically powerful, it must offer core engineering insights.

- Finite Element Method (FEM) Engine (critical for accuracy)
Internally simulate material stress, strain, and load transfer across structural components using FEM or simplified models.
Differentiate between materials (steel, concrete, wood) with varying elasticity, ductility, and failure thresholds.
- Structural Component Behavior Tracking
Monitor deformation of key components:
Beams, columns, walls, joints.
Detect and log overstressed or failed regions.
- Resonance and Damping Effects
Account for natural frequency of structures and evaluate resonance amplification.
Allow configuration of damping factors (passive or active dampers).

### Performance Metrics

Quantitative analysis is vital for evaluating the impact of simulated seismic events.

- Live Metric Dashboards
Display values such as:
Peak Ground Acceleration (PGA)
Maximum Interstory Drift Ratio
Stress/Strain over time
Total energy absorbed or dissipated
- Safety and Compliance Evaluation
Estimate damage levels and categorize them (Minor, Moderate, Severe, Collapse).
Check for compliance with structural safety codes (optionally based on region-specific norms, like Eurocode or ASCE).
- Report Generation and Export
Generate detailed simulation reports including:
Structural performance summary.
Time-series graphs and visual data overlays.
Breakdown of failure points and likely causes.
Export reports in formats like PDF, CSV, or JSON for integration into external tools.

---

## Non-functional Requirements

---
