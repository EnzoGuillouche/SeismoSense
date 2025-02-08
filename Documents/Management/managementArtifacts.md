# Management Artifacts - SeismoSense

This document aims to centralize all the management artifact links and resources listed below:

- [Management Artifacts - SeismoSense](#management-artifacts---seismosense)
  - [Project Overview](#project-overview)
  - [Risks \& Assumptions](#risks--assumptions)
  - [Key Performance Indicators](#key-performance-indicators)
    - [Definition of our KPIs](#definition-of-our-kpis)
      - [Documents](#documents)
      - [Development](#development)
    - [Link to the project's KPIs](#link-to-the-projects-kpis)
  - [Monthly reports](#monthly-reports)

## Project Overview

SeismoSense is a cutting-edge earthquake simulation tool designed to test the structural resilience of buildings and other infrastructure under various seismic scenarios.
Built with C++ and OpenGL, this project focuses on real-time visualization and precise simulation of seismic impacts. It aims to empower engineers, researchers, and urban planners with data-driven insights to better prepare for and mitigate earthquake risks.

## Risks & Assumptions

| ID | Description | Consequence | Impact | Likelihood | Mitigation/Avoidance |
| --- | --- | --- | --- | --- | --- |
| 1 | Real-time physics simulation requires high computational resources. | Performance issues on lower-end hardware. | High | Medium | Optimize rendering and simulation efficiency. |
| 2 | The accuracy of the simulation depends on the quality of input seismic data.| Potential discrepancies between simulation and real-world effects. | High | Medium | Use validated seismic datasets and implement rigorous testing. |
| 3 | Visualization using OpenGL might not be compatible with all systems. | Limited accessibility for some users. | Medium | Low | Provide configuration options for different hardware setups. |
| 4 | Integration of real-world building structures might be complex. | Delays in model implementation and usability. | High | Medium | Develop a modular approach to add building models progressively. |
| 5 | Balancing accuracy and performance might be challenging. | Compromises in either speed or fidelity. | High | Medium | Implement adjustable settings for accuracy vs. performance trade-offs. |

## Key Performance Indicators

### Definition of our KPIs

To be able to track our project's milestones, I have defined several quantitatively measurable KPIs. Below is a list of these KPIs along with their respective calculations.

#### Documents

The following KPIs are included in this section:

- **Functional Specifications** - Completion percentage of functional documentation.
- **Technical Specifications** - Documentation coverage of system architecture and implementation.
- **Test Plan** - Number of test cases created and executed.
- **User Manual** - Completion of end-user documentation.

#### Development

This section tracks the following KPIs:

- **Simulation Performance** - Frame rate and computational efficiency.
- **Accuracy of Seismic Models** - Comparison with real-world earthquake data.
- **User Engagement** - Number of testers and feedback received.
- **Bug Resolution Rate** - Number of issues resolved per development cycle.

### Link to the project's KPIs

You can see my project's KPIs which were explained above following [this link](https://docs.google.com/spreadsheets/d/1_1VExDz2joEaqKS-Hz4ZBdCjuZoT1MlYCAUyJKzdaAI/edit?usp=sharing).

## Monthly reports

The monthly reports folder can be found following [this link](/Documents/Management/MonthlyReports/).

You can directly access the reports individually following the below bullet points:

- [Access Report for Month 1](/Documents/Management/MonthlyReports/month1.md)
- [Access Report for Month 2](/Documents/Management/MonthlyReports/month2.md)
- [Access Report for Month 3](/Documents/Management/MonthlyReports/month3.md)
- [Access Report for Month 4](/Documents/Management/MonthlyReports/month4.md)
- [Access Report for Month 5](/Documents/Management/MonthlyReports/month5.md)

For a centralized collection of copies of all the reports in a single document, please refer to the Cumulative File for Monthly Reports:

- [Access Cumulative file for all 5 months](/Documents/Management/MonthlyReports/cumulative.md)
