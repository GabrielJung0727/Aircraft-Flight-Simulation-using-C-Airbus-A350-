#include <stdio.h>
#include <math.h>

// Airbus A350 항공기 특성
typedef struct {
    double mass;      // 항공기 질량 (kg)
    double thrust;    // 엔진 추력 (N)
    double drag_coef; // 항력 계수
    double wing_area; // 날개 면적 (m^2)
} Aircraft;

// 항력 계산 함수
double calculate_drag(double velocity, double drag_coef, double wing_area, double air_density) {
    return 0.5 * air_density * velocity * velocity * drag_coef * wing_area;
}

// 비행 시뮬레이션 함수
void simulate_flight(Aircraft *aircraft, double duration, double time_step) {
    double velocity = 0.0;
    double altitude = 10000.0; // 초기 고도 (m)
    double position = 0.0;
    double air_density;
    double gravity = 9.81; // 중력 가속도 (m/s^2)

    // 시뮬레이션 시간 동안 반복
    for (double t = 0; t < duration; t += time_step) {
        // 고도에 따른 공기 밀도 계산 (단순화된 모델)
        air_density = 1.225 * exp(-altitude / 8500.0); // kg/m^3

        // 항력 계산
        double drag = calculate_drag(velocity, aircraft->drag_coef, aircraft->wing_area, air_density);

        // 상승/하강에 따른 추가 항력 및 중력 고려
        double net_force = aircraft->thrust - drag - (aircraft->mass * gravity);

        // 가속도 계산
        double acceleration = net_force / aircraft->mass;

        // 속도 및 위치 업데이트
        velocity += acceleration * time_step;
        position += velocity * time_step;

        // 출력
        printf("Time: %.2f s, Position: %.2f m, Velocity: %.2f m/s, Altitude: %.2f m\n", t, position, velocity, altitude);

        // 고도 업데이트 (단순한 모델, 실제로는 더 복잡함)
        altitude += velocity * time_step * 0.01; // 고도 변화량 (m)
    }
}

int main() {
    // Airbus A350의 특성
    Aircraft a350 = {280000, 2 * 320000, 0.024, 443}; // 대한항공 Airbus A350의 기본 파라미터
    double duration = 3600.0; // 시뮬레이션 시간 (초)
    double time_step = 1.0; // 시간 간격 (초)

    // 비행 시뮬레이션 실행
    simulate_flight(&a350, duration, time_step);
    return 0;
}



// Aircraft 구조체: Airbus A350의 특성을 정의
// mass: 항공기 질량
// thrust: 엔진 추력
// drag_coef: 항력 계수
// wing_area: 날개 면적
// calculate_drag 함수: 항력을 계산
// simulate_flight 함수: 주어진 시간 동안 항공기의 비행을 시뮬레이션
// air_density: 고도에 따른 공기 밀도 계산
// net_force: 순 힘 계산
// acceleration: 가속도 계산
// velocity와 position: 속도 및 위치 업데이트
// altitude: 고도 업데이트