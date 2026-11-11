CREATE TABLE IF NOT EXISTS devices(
    id INTEGER PRIMARY KEY,
    device_type TEXT NOT NULL CHECK(device_type in ('GPU')),
    model INTEGER,
    vendor INTEGER
);

CREATE TABLE IF NOT EXISTS gpu_properties(
    id INTEGER PRIMARY KEY,
    device_id INTEGER UNIQUE,
    clock_speed NUMERIC,
    vram_capacity NUMERIC,

    FOREIGN KEY(device_id) REFERENCES devices(id)
);
